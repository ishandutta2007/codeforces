#include<bits/stdc++.h>
typedef double ld;
using namespace std;

const size_t DEEP = 40;

/*
void print(vector< vector<ld> > a, int x) {
    for (int i = 0; i < a[x].size(); ++i) {
        cerr << (double)a[x][i] << " ";
    }
    cerr << endl;
}
*/
                  
int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int q;
    scanf("%d", &q);    

    vector<int> pr(2);
    vector<vector<ld>> f(2);
    f[1] = vector<ld>(DEEP, 1.0);

    while (q--) {
        int type, v;
        scanf("%d%d", &type, &v);

        if (type == 1) {
            pr.push_back(v);
            f.push_back(vector<ld>(DEEP, 1.0));
            int x = pr.size() - 1;

            vector<int> prs(1, x);
            prs.reserve(DEEP + 1);

            for (size_t it = 1; it <= DEEP; ++it) {
                if (pr[prs.back()] == 0) break;
                prs.push_back(pr[prs.back()]);
            }

            for (int i = (int)prs.size() - 1; i > 1; --i) {
                int p = prs[i];
                int xx = prs[i - 1];

                for (size_t j = 0; j < DEEP; ++j) {                    
                   ld old;
                   if (j == 0)
                      old = 0.5;
                   else
                      old = f[xx][j - 1] + 0.5 * (1 - f[xx][j - 1]);

                   f[p][j] /= old;
                }
            }

            for (size_t i = 0; i + 1 < prs.size(); ++i) {
                int x = prs[i];
                int p = prs[i + 1];

                for (size_t j = 0; j < DEEP; ++j) {
                    ld nw;
                    if (j == 0)
                        nw = 0.5;
                    else
                        nw = f[x][j - 1] + 0.5 * (1 - f[x][j - 1]);

                    f[p][j] *= nw;
                }
            }

        } else {
//            cout << "ask" << endl;

            ld ans = 0;
            for (size_t i = 1; i < DEEP; ++i) {
                ans += (f[v][i] - f[v][i - 1]) * i;
            }

            printf("%.12f\n", (double)ans);
        }

        /*
        for (int x = 1; x < f.size(); ++x) {
            cout << x << ": ";
            for (int j = 0; j < DEEP; ++j) {
                cout << (double)f[x][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
    }

//    cerr << clock() << endl;

    return 0;
}