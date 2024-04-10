#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n;
    cin >> n;
    int A[1000][1000];
    REP(y, n) REP(x, n) scanf("%d", &A[y][x]);
    int q;
    cin >> q;
    int ans = 0;
    REP(y, n) ans ^= A[y][y];
    while(q--){
        int type;
        scanf("%d", &type);
        if(type == 1 || type == 2){
            int d;
            scanf("%d", &d);
            ans ^= 1;
        }else {
            printf("%d", ans);
        }
    }
    puts("");
    return 0;
}