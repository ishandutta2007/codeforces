#include <bits/stdc++.h>

using namespace std;

int T, N;
char s[104];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        scanf("%s", s+1);
        int f = 0;
        for(int i=1;i<=N/2;++i){
            int j = N-(i-1);
            if(!(s[i]+1==s[j]+1||s[i]+1==s[j]-1||s[i]-1==s[j]+1||s[i]-1==s[j]-1)){
                f = 1; break;
            }
        }
        if(!f) puts("YES");
        else puts("NO");
    }

    return 0;
}