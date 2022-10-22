#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=41;
const ll inf=0x3f3f3f3f3f3f3f3f;
int a[mn],b[mn];
int v[mn];
ll t[mn][mn];
void mult(ll c[mn][mn],ll a[mn][mn],ll b[mn][mn]){
	memset(t,0x3f,sizeof(t));
	for(int i=0;i<mn;i++)for(int j=0;j<mn;j++)for(int k=0;k<mn;k++)t[i][k]=min(t[i][k],a[i][j]+b[j][k]);
	memcpy(c,t,sizeof(t));
}
ll A[mn][mn],tr[mn][mn],ans[mn][mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    memset(A,0x3f,sizeof(A));
    for(int i=0;i<mn;i++)A[i][i]=0;
    memcpy(ans,A,sizeof(A));
    for(int i=0;i<n;i++){
    	memset(tr,0x3f,sizeof(tr));
    	for(int j=0;j+1<mn;j++)tr[j][j+1]=a[i],tr[j+1][j]=b[i];
    	mult(A,A,tr);
    }
	for(int b=m;b;b>>=1,mult(A,A,A))if(b&1)mult(ans,ans,A);
	printf("%lld",ans[0][0]);
}