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

const int N = 105;

int n;
char s[N];

int main () {
    int ttt;
    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &n);
        int first_zero = -1;
        for (int i = 0; i < n; i++) {
            scanf(" %c", &s[i]);
            if (first_zero == -1 and s[i] == 0) first_zero = i;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == '0') {
                        if (j - i == 1) ans += 2;
                        else if (j - i == 2) ans += 1;

                        break;
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}