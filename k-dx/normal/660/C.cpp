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

const int N = 3e5+5;

int n, k;
int t[N];

int main () {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    int ans = 0;
    int l = -1, r = -1;
    int dupa = 0;
    int ile_zer = 0;
    // [dupa, i]
    for (int i = 0; i < n; i++) {
        if (t[i] == 0) ile_zer++;

        while (ile_zer > k and dupa < i) {
            if (t[dupa] == 0) ile_zer--;
            dupa++;
        }

        if (ile_zer <= k and i - dupa + 1 > ans) {
            ans = i - dupa + 1;
            l = dupa;
            r = i;
        }
    }

    for (int i = l; i <= r; i++)
        t[i] = 1;

    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
        printf("%d ", t[i]);
    printf("\n");

    return 0;
}