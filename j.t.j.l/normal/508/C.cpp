#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

int i,j,n,m,t,r,ans,p;
int a[2000],candle[2000];

int main(){
    cin>>m>>t>>r;
    rep(i,1,m)
        scanf("%d",&a[i]);
    if (t<r){
        cout<<-1<<endl;
        return 0;
    }
    rep(i,1,r)
        candle[i]=-1000;
    ans=0;
    rep(i,1,m){
        p=0;
        rep(j,1,r)
            if (candle[j]+t<a[i]){
                p++;
                candle[j]=a[i]-p;
                ans++;
            }
    }
    cout<<ans<<endl;
    return 0;
}