#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)104;
int T, N, Q;
int a[NS];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &Q);
        for(int i = 1; i <= N; ++i){
            scanf("%1d", a + i);
        }
        while(Q--){
            int l, r; scanf("%d %d", &l, &r);
            int f = 0;
            for(int i = 1; i < l; ++i){
                if(a[i] == a[l]){
                    f = 1;
                }
            }
            for(int i = N; i > r; --i){
                if(a[i] == a[r]){
                    f = 1;
                }
            }
            if(f){
                puts("YES");
            }
            else{
                puts("NO");
            }
        }
    }
    return 0;
}