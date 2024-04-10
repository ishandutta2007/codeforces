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

int n, m;

const vector<pair<int,int>> MVS{
    {-2, -1},
    {-1, -2},
    { 1, -2},
    { 2, -1},
    { 2,  1},
    { 1,  2},
    {-1,  2},
    {-2,  1}
};

bool on_board (int x, int y) {
    return x >= 1 and y >= 1 and x <= m and y <= n;
}

void solve () {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) { // column 
        for (int j = 1; j <= n; j++) { // row
            bool isolated = true;
            for (auto p : MVS) {
                if (on_board(i+p.first, j+p.second)) {
                    isolated = false;
                    break;
                }
            }

            if (isolated) {
                printf("%d %d\n", j, i);
                return;
            }
        }
    }

    printf("1 1\n");
}

int main () {
    int ttt;
    scanf("%d", &ttt);
    while (ttt--) {
        solve();
    }
    return 0;
}