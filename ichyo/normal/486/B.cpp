#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int H, W;
    while(cin >> H >> W) {
        int A[100][100] = {};
        REP(y, H) REP(x, W) A[y][x] = 1;
        int B[100][100];
        REP(y, H) REP(x, W) {
            int t;
            cin >> t;
            B[y][x] = t;
            if(t == 0) {
                REP(i, H) A[i][x] = 0;
                REP(j, W) A[y][j] = 0;
            }
        }

        int C[100][100] = {};
        REP(y, H) REP(x, W) if(A[y][x]) {
            REP(i, H) C[i][x] = 1;
            REP(j, W) C[y][j] = 1;
        }

        bool ok = true;
        REP(y, H) REP(x, W) if(C[y][x] != B[y][x]) ok = false;
        cout << (ok ? "YES" : "NO") << endl;
        if(ok) {
            REP(y, H) {
                REP(x, W) {
                    cout << A[y][x];
                    if(x == W - 1) cout << endl;
                    else cout << " ";
                }
            }
        }
    }
    return 0;
}