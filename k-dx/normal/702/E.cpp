#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 1e5+5;
const int LOGK = 34;

int n;
ll k;
int f[N];
int w[N];
ll s[N][LOGK];
int m[N][LOGK];
int jump[N][LOGK];
ll ans_s[N][LOGK];
int ans_m[N][LOGK];

int main () {
    scanf("%d %lld", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &f[i]);
        jump[i][0] = f[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        s[i][0] = w[i];
        m[i][0] = w[i];
    }

    for (int i = 1; i < LOGK; i++) {
        for (int j = 0; j < n; j++) {
            jump[j][i] = jump[jump[j][i-1]][i-1];
        }
    } 

    for (int i = 1; i < LOGK; i++) {
        for (int j = 0; j < n; j++) {
            s[j][i] = s[j][i-1] + s[jump[j][i-1]][i-1];
            m[j][i] = min(m[j][i-1], m[jump[j][i-1]][i-1]);
        }
    }

    for (int i = 0; i < n; i++) {
        int akt = i;
        ll sum = 0;
        int minw = INT_MAX;
        for (ll j = LOGK; j >= 0; j--) {
            if ((1LL << j) & k) {
                deb("skacze o 2 ^ %d = %d\n", j, (1 << j));
                sum += s[akt][j];
                minw = min(minw, m[akt][j]);
                akt = jump[akt][j];
            }
        }
        printf("%lld %d\n", sum, minw);
    }

    return 0;
}