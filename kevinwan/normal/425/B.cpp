#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=101;
int a[mn][mn],tar[mn];
int n,m,k;
int ans=0x3f3f3f3f;
int solve(){
    int ans=0;
    for(int i=1;i<=n;i++){
        vector<int>v;
        for(int j=1;j<m;j++)if(a[i][j]!=tar[j])v.push_back(j);
        if(!v.size())continue;
        int p1=0,p2=0;
        for(int j=0;j+1<v.size();j+=2)p1+=v[j+1]-v[j];
        if(v.size()&1)p1+=m-v.back();
        p2+=v[0];
        for(int j=1;j+1<v.size();j+=2)p2+=v[j+1]-v[j];
        if(!(v.size()&1))p2+=m-v.back();
        ans+=min(p1,p2);
        if(ans>k)return 0x3f3f3f3f;
    }
    return ans;
}
void stupid(int i,int l){
    if(i>=m){
        ans=min(ans,solve());
    }
    else{
        stupid(i+1,l);
        if(l){
            tar[i]^=1;
            tar[i+1]^=1;
            stupid(i+1,l-1);
            tar[i]^=1;
            tar[i+1]^=1;
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
    if(n<m){
        swap(n,m);
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)swap(a[i][j],a[j][i]);
    }
    for(int i=1;i<=n;i++)for(int j=1;j<m;j++)a[i][j]^=a[i][j+1];

    if(n>2*k){
        for(int i=1;i<m;i++){
            int num=0;
            for(int j=1;j<=n;j++)num+=a[j][i];
            if(num<=k)tar[i]=0;
            else tar[i]=1;
        }
        ans=solve();
    }
    else{
        for(int i=1;i<m;i++)tar[i]=a[1][i];
        stupid(0,k);
    }
    printf("%d",ans<=k?ans:-1);
}