#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=100;
const ll mod=1e6+3;
typedef pair<ll,ll>pll;
int d[mn][mn];
int p[10];
pii d2[mn][mn][mn];
bool op[mn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&d[i][j]);
    for(int i=0;i<n;i++)d[i][i]=0x3f3f3f3f;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            d2[i][j][k]={d[i][k]+d[k][j],k};
        }
        sort(d2[i][j],d2[i][j]+n);
    }
    p[0]=1,p[1]=n;
    for(int i=2;i<=k/2-1;i++)p[i]=p[i-1]*n;
    int ans=0x3f3f3f3f;
    int num=0;
    vector<int>pth(k/2+1);
    for(int i=0;i<p[k/2-1];i++){
        for(int j=0;j<k/2-1;j++)pth[j+1]=(i/p[j]%n);
        for(int x:pth)op[x]=1;
        int l=0;
        for(int j=1;j<pth.size();j++){
            bool bad=1;
            for(int k=0;k<n;k++)if(!op[d2[pth[j-1]][pth[j]][k].second]){
                //num++;
                l+=d2[pth[j-1]][pth[j]][k].first;
                bad=0;
                break;
            }
            if(bad){
                l=0x3f3f3f3f;
                goto hail;
            }
        }
        hail:
        ans=min(ans,l);
        for(int x:pth)op[x]=0;
    }
    printf("%d",ans);
}