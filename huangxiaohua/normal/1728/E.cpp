#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,ty,x,y,a[300005];
ll b,f[300005],res;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b;
		f[0]+=b;a[i]-=b;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)f[i]=f[i-1]+a[n+1-i];
	map<tuple<int,int,int>,ll>g;
	cin>>t;
	while(t--){
		cin>>x>>y;
		if(x<y)swap(x,y),ty=1;
		else ty=0;
		if(g.count({x,y,ty})){cout<<g[{x,y,ty}]<<'\n';continue;}
		res=-1;
		for(i=0;i<=n;i+=x)if(!((n-i)%y)){
			if(!ty)res=max(res,f[i]); else res=max(res,f[n-i]);
		}
		cout<<(g[{x,y,ty}]=res)<<'\n';
	}
}//