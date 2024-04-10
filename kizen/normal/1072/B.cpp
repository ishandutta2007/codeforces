#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5+4;
int N;
int A[NS], B[NS];
int ans[NS];

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N-1;++i) scanf("%d", A+i);
    for(int i=1;i<=N-1;++i) scanf("%d", B+i);
    for(int k=0;k<=3;++k){
        memset(ans, -1, sizeof(ans));
        ans[1] = k;
        for(int i=2;i<=N;++i){
            for(int j=0;j<=3;++j) if((ans[i-1]|j)==A[i-1]&&(ans[i-1]&j)==B[i-1]){
                ans[i] = j; break;
            }
            if(ans[i]==-1) break;
        }
        if(ans[N]!=-1){
            puts("YES");
            for(int i=1;i<=N;++i) printf("%d ", ans[i]); return 0;
        }
    }
    puts("NO");
    return 0;
}