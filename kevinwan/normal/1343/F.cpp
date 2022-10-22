#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=200+10;
vector<int>ch[mn],par[mn];
bool u[mn];
int num[mn];
bool don[mn];
int cnt[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)ch[i].clear(),par[i].clear();
        for(int i=0;i<n-1;i++){
            int m;
            cin>>m;
            while(m--){
                int x;
                cin>>x;
                ch[i].push_back(x);
                par[x].push_back(i);
            }
        }
        for(int beg=1;beg<=n;beg++){
            for(int i=1;i<=n;i++)num[i]=par[i].size();
            num[beg]=0;
            memset(u,0,sizeof(u));
            vector<int>ans;
            for(int i=0;i<n-1;i++){
                int x=-1;
                for(int j=1;j<=n;j++)if(num[j]==1)x=j;
                if(x==-1)break;
                for(int y:par[x])if(!u[y]){
                    u[y]=1;
                    for(int z:ch[y])num[z]--;
                }
                ans.push_back(x);
            }
            if(ans.size()!=n-1)continue;
            ans.push_back(beg);
            reverse(ans.begin(),ans.end());
            memset(don,0,sizeof(don));
            for(int i=0;i<n-1;i++){
                memset(cnt,0,sizeof(cnt));
                int fff=ch[i].size();
                for(int x:ch[i])cnt[x]=1;
                for(int j=0;j<n;j++){
                    fff-=abs(cnt[ans[j]]--);
                    fff+=abs(cnt[ans[j]]);
                    if(j-(int)ch[i].size()>=0){
                        fff-=abs(cnt[ans[j-ch[i].size()]]++);
                        fff+=abs(cnt[ans[j-ch[i].size()]]);
                    }
                    if(!fff){
                        don[j]=1;
                        break;
                    }
                }
            }
            bool f=0;
            for(int i=1;i<n;i++)f|=!don[i];
            if(f)continue;
            for(int x:ans)printf("%d ",x);
            printf("\n");
            break;
        }
    }
}