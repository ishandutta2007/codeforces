#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,res; int k,tot; ll a[11];
bool ans;
void dfs(ll u,ll s,bool ok){
	if (u==r+1){
		if (tot){
			if (ok&&s==res){
				cout<<res<<'\n'<<tot<<'\n';
				for (int i=1;i<=tot;i++) cout<<a[i]<<' ';
				cout<<'\n'; exit(0);
			}
			if (s<res) res=s;
		}
		return;
	}
	dfs(u+1,s,ok);
	if (tot<k){ a[++tot]=u; dfs(u+1,s^u,ok); tot--;}
}
int main(){
	cin>>l>>r>>k; ans=false;
	if (k==1) cout<<l<<'\n'<<1<<'\n'<<l<<'\n';
	else
		if (r<l+4){
			res=1ll<<60; dfs(l,0,false);
			dfs(l,0,true);
		}
		else{
			ll u=l+(l&1);
			if (k>=4){ ans=true; cout<<0<<'\n'<<4<<'\n'<<u<<' '<<u+1<<' '<<u+2<<' '<<u+3<<'\n';}
			else
				if (k==3){
					for (int x=40;x>=1&&!ans;x--)
						for (int i=x-1;i>=0&&!ans;i--)
							if ((1ll<<(i+1))-1>=l&&(1ll<<x)+(1ll<<i)<=r){
								ans=true;
								cout<<0<<'\n'<<3<<'\n'<<(1ll<<(i+1))-1<<' '<<(1ll<<x)+(1ll<<i)-1<<' '<<(1ll<<x)+(1ll<<i)<<'\n';
							}
				}
			if (!ans) cout<<1<<'\n'<<2<<'\n'<<u<<' '<<u+1<<'\n';
		}
	return 0;
}