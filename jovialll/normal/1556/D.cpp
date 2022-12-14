#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define int long long
int ans[N],f[N],n,k,i,x,y;
signed main(){
	cin>>n>>k;
	for(i=1;i<n;++i){
		cout<<"or "<<i<<" "<<n<<'\n';cout.flush();
		cin>>x;
		cout<<"and "<<i<<" "<<n<<'\n';cout.flush();
		cin>>y;
		f[i]=x+y;
	}
		cout<<"or "<<1<<" "<<2<<'\n';cout.flush();
		cin>>x;
		cout<<"and "<<1<<" "<<2<<'\n';cout.flush();
		cin>>y;
	ans[n]=(f[1]+f[2]-x-y)/2;
	for(i=1;i<n;++i)ans[i]=f[i]-ans[n];
	sort(ans+1,ans+n+1);
	cout<<"finish "<<ans[k];
}