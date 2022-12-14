#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5+4;
int N;
char A[NS], B[NS];
int cnt[5][5];

int main(){
    scanf("%d", &N);
    scanf("%s %s", A+1, B+1);
    for(int i=N;i>=1;--i) ++cnt[A[i]-'0'][B[i]-'0'];

    long long ans = 0;
    for(int i=1;i<=N;++i){
        --cnt[A[i]-'0'][B[i]-'0'];
        if(A[i]=='0'&&B[i]=='0'){
            ans += cnt[1][0]+cnt[1][1];
        }
        else if(A[i]=='0'&&B[i]=='1'){
            ans += cnt[1][0];
        }
        else if(A[i]=='1'&&B[i]=='0'){
            ans += cnt[0][0]+cnt[0][1];
        }
        else{
            ans += cnt[0][0];
        }
    }
    printf("%I64d", ans);

    return 0;
}