#include <bits/stdc++.h>

using namespace std;
int in[200020];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%d",&in[i]);
        sort(begin(in)+1,begin(in)+n+1);
        int ans=0;
        int cnt=-1,ma=0;
        for(int i=1; i<=n; i++){
            if(cnt==-1||cnt>=ma){
                cnt=1;
                ans++;
            }else{
                cnt++;
            }
            ma=max(in[i],ma);
            // printf("::%d %d\n",cnt,ma);
        }
        if(cnt>=ma)ans++;
        printf("%d\n",ans-1);
    }
    return 0;
}