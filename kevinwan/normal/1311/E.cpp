#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=5e3+10;
int p[mn],dep[mn],us[mn];
set<int>rem0[mn],rem1[mn];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,d,u=0;
        scanf("%d%d",&n,&d);
        for(int i=0;i<=n;i++)rem0[i].clear(),rem1[i].clear(),p[i]=dep[i]=us[i]=0;
        for(int i=2;i<=n;i++)p[i]=i/2,dep[i]=dep[i/2]+1,u+=dep[i],us[i/2]++;
        for(int i=1;i<=n;i++){
            if(us[i]==0)rem0[dep[i]].insert(i);
            else if(us[i]==1)rem1[dep[i]].insert(i);
        }
        if(u>d||d>n*(n-1)/2){
            printf("NO\n");
            continue;
        }
        while(u<d){
            int cur=-1;
            for(int i=n;i>=1;i--){
                if(rem0[i].size()>=1&&rem0[i].size()+rem1[i].size()>=2){
                    cur=i;
                    break;
                }
            }
            int x=*rem0[cur].begin(),y;
            rem0[cur].erase(x);
            rem0[cur+1].insert(x);
            int par=p[x];
            us[par]--;
            rem1[cur-1].erase(par);
            if(us[par])rem1[cur-1].insert(par);
            else rem0[cur-1].insert(par);
            if(rem0[cur].size())y=*rem0[cur].begin();
            else y=*rem1[cur].begin();
            p[x]=y;
            us[y]++;
            rem0[cur].erase(y);
            rem1[cur].erase(y);
            if(us[y]==1)rem1[cur].insert(y);
            u++;
        }
        printf("YES\n");
        for(int i=2;i<=n;i++)printf("%d ",p[i]);
        printf("\n");
    }
}