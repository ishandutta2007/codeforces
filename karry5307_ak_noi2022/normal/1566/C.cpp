#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n;
char s[2][100010];
void solve(){int ans=0;
    scanf("%d %s %s",&n,s[0]+1,s[1]+1);
    for(int i=1,j=0;i<=n+1;i++){
        if(s[0][i]==s[1][i]&&i<=n) continue;
        ans+=2;
        // printf("%d %d\n",i,j);
        if(i==j+1){j=i;continue;}
        int cnt[2]={0,0};
        cnt[s[0][j+1]-'0']++;
        for(int t=j+2,l=j;t<i;t++){
            cnt[s[0][t]-'0']++;
            if(l==t-1) continue;
            if(s[0][t]!=s[0][t-1]){
                ans+=2;
                cnt[s[0][t]-'0']--;
                cnt[s[0][t-1]-'0']--;
                l=t;
            }
        }
        ans+=cnt[0];j=i;
    }
    printf("%d\n",ans-2);
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&T);
    while(T--) solve();
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}