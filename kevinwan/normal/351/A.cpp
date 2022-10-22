#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=4e3+10;
const ll inf=0x3f3f3f3f3f3f3f3f;

int a[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>n;
    int nc=0;
    for(int i=0;i<n*2;i++){
    	double x;
    	cin>>x;
    	a[i]=(x*1000+0.5);
    	a[i]%=1000;
    	if(!a[i])nc++;
    }
    int s=0;
    for(int i=0;i<n*2;i++)s+=a[i];
    int ans=inf;
    for(int i=0;i<=n;i++)if(i<=2*n-nc&&n-i<=nc){
    	ans=min(ans,abs(s-1000*i));
    }
    printf("%.3lf",ans*.001);
}