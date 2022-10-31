#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

map<ll,int> id;
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
int i,j,k,t,n,m,it,ty[200500];
ll f[200500][4],sb,res,tmp,inv;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
string s;

void dfs(ll x){
	int i,j,k,cur,ls,rs;
	k=id[x];
	f[k][1]=f[k][2]=f[k][3]=1;
	ls=rs=0;
	if(id.count((x<<1)|0)){
		dfs((x<<1)|0);
		ls=id[(x<<1)|0];
		f[k][1]*=(f[ls][2]+f[ls][3]);f[k][1]%=M;
		f[k][2]*=(f[ls][1]+f[ls][3]);f[k][2]%=M;
		f[k][3]*=(f[ls][1]+f[ls][2]);f[k][3]%=M;
	}
	if(id.count((x<<1)|1)){
		dfs((x<<1)|1);
		rs=id[(x<<1)|1];
		f[k][1]*=(f[rs][2]+f[rs][3]);f[k][1]%=M;
		f[k][2]*=(f[rs][1]+f[rs][3]);f[k][2]%=M;
		f[k][3]*=(f[rs][1]+f[rs][2]);f[k][3]%=M;
	}
	if(ty[k]==1)f[k][2]=f[k][3]=0;
	if(ty[k]==2)f[k][1]=f[k][3]=0;
	if(ty[k]==3)f[k][1]=f[k][2]=0;
}

int main() {
	cin.tie(0);
	cin>>n>>t;
	m=t;
	while(t--){
		cin>>sb>>s;
		if(!id[sb]){
			id[sb]=++it;
		}
		int cur=id[sb];
		if(s=="white"||s=="yellow")ty[cur]=1;
		if(s=="green"||s=="blue")ty[cur]=2;
		if(s=="red"||s=="orange")ty[cur]=3;
		while(sb){
			if(!id[sb])id[sb]=++it;
			sb>>=1;
		}
	}
	dfs(1);
	res=f[id[1]][1]+f[id[1]][2]+f[id[1]][3];
	res%=M;
	res=res*ksm(2,it-m)%M*ksm(4,(1ll<<n)-1-it)%M;
	cout<<res;
}