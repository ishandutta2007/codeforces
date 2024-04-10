#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 110;

int n, k, A[M * M], Chk[M * M], Pos[M];
pint Ans[M];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n * k; i++) {
        cin >> A[i];
    }   
    for (int i = 1, p = 1; i <= n; i++) {
        memset(Pos, -1, sizeof Pos);   
        while (1) {
            if (p == n * k + 1) {
                memset(Pos, -1, sizeof Pos);
                p = 1;
            }
            int x = A[p];
            if (Chk[x]) {
                p += 1; continue;
            }
            if (Pos[x] == -1) {
                Pos[x] = p; 
            }
            else {
                Ans[x] = { Pos[x], p };
                Chk[x] = 1; 
                p += 1; break;
            }
            p += 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << Ans[i].va << ' ' << Ans[i].vb << '\n';
    }
}