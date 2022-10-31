#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000009
int i,j,k,n,m,t;
ll f[300500],p[300500],a[300500],res,d[300500];
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
vector<pair<int,int> >v;
void upd(){
	memset(d,0,sizeof(d));
	for(auto [l,r]:v){
		d[l]++;
		d[r+1]=su(d[r+1],M-f[r-l+2]);
		d[r+2]=su(d[r+2],M-f[r-l+1]);
	}
	for(i=2;i<=n;i++){
		d[i]=su(d[i],su(d[i-1],d[i-2]));
	}
	for(i=1;i<=n;i++){
		d[i]=su(d[i],d[i-1]);
		a[i]=su(a[i],d[i]);
	}
	v.clear();
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	f[1]=p[1]=1;
	for(i=2;i<=300050;i++){
		f[i]=su(f[i-1],f[i-2]);
		p[i]=su(p[i-1],f[i]);
	}
	cin>>n>>t;
	for(i=1;i<=n;i++){
		cin>>k;a[i]=su(a[i-1],k);
	}
	while(t--){
		int op,l,r;
		cin>>op>>l>>r;
		if(op==1){
			v.push_back({l,r});
			if(v.size()==1000)upd();
		}
		else{
			res=su(a[r],M-a[l-1]);
			for(auto [x,y]:v){
				i=max(x,l)-x+1;
				j=min(y,r)-x+1;
				if(i<=j)res=su(res,su(p[j],M-p[i-1]));
			}
			cout<<res%M<<'\n';
		}
	}
}