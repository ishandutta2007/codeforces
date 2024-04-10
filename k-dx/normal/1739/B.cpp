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

const int N = 0;

int n;

void solve() {
    scanf("%d", &n);
    vector<int> ans(n);
    scanf("%d", &ans[0]);

    vector<int> d(n);
    for (int i = 1; i < n; i++) {
        scanf("%d", &d[i]);
    }

    for (int i = 1; i < n; i++) {
        if (d[i] != 0 and ans[i-1] - d[i] >= 0) {
            printf("-1\n");
            return;
        }

        ans[i] = ans[i-1] + d[i];
    }

    for (int e : ans) {
        printf("%d ", e);
    }
    printf("\n");
}

int main () {
    int ttt;
    scanf("%d", &ttt);
    while (ttt--) {
        solve();
    }
    return 0;
}