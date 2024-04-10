#include<bits/stdc++.h>
using namespace std;
int T,n;char s[100010],s2[100010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %s %s",&n,s+1,s2+1);
        bool pd=1,pd2=1;
        for(int i=1;i<=n;i++){
            if(s[i]!=s2[i]) pd=0;
            if(s[i]!='0') pd2=0;
        }if(pd){puts("0");continue;}
        if(pd2){puts("-1");continue;}
        int cnt=0,cnt2=0;
        for(int i=1;i<=n;i++){
            cnt+=s[i]-'0';
            cnt2+=s2[i]-'0';
        }
        if(cnt!=cnt2&&cnt+cnt2!=n+1){puts("-1");continue;}
        int minn=2e9;
        if(cnt==cnt2){int ans=0;
            for(int i=1;i<=n;i++){
                if(s[i]!=s2[i]) ans++;
            }
            if(ans%2==0) minn=min(minn,ans);
        }
        if(cnt+cnt2==n+1){
            for(int i=1;i<=n;i++) s2[i]=s2[i]=='0'?'1':'0';
            int cnt[2]={0,0};
            for(int i=1;i<=n;i++){
                if(s[i]=='0'&&s2[i]=='1') cnt[0]++;
                if(s[i]=='1'&&s2[i]=='0') cnt[1]++;
            }
            if(cnt[1]==cnt[0]+1) minn=min(minn,cnt[0]*2+1);
        }
        printf("%d\n",minn>1e9?-1:minn);
    }
    return 0;
}
//x n-x+1 x