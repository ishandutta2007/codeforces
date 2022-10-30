#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,t,n,m,q,ti,a[100500],b[100500],l[100500],r[100500],it;
ll pw[100500],res[100500];
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
vector<int> v[200500];

#define md ((l+r)/2)
#define ls (id*2)
#define rs (ls+1)
void add(int id,int l,int r,int x,int y,int w){
	if(x<=l&&r<=y){v[id].push_back(w);return;}
	if(x<=md)add(ls,l,md,x,y,w);
	if(y>md)add(rs,md+1,r,x,y,w);
}

void get(int id,int l,int r,vector<int> f){
	for(auto i:v[id])for(j=m;j>=a[i];j--)f[j]=max(f[j],f[j-a[i]]+b[i]);
	if(l==r){
		for(int i=1;i<=m;i++)res[l]=su(res[l],pw[i]*f[i]%M);
		return;
	}
	get(ls,l,md,f);get(rs,md+1,r,f);
}

int main() {
	memset(r,-1,sizeof(r));
	pw[1]=1;for(i=2;i<=100000;i++)pw[i]=pw[i-1]*10000019%M;
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){cin>>b[i]>>a[i];l[i]=1;}
	it=n;
	cin>>t;
	for(i=1;i<=t;i++){
		int ty;cin>>ty;
		if(ty==1){it++;cin>>b[it]>>a[it];l[it]=ti+1;}
		if(ty==2){cin>>k;r[k]=ti;}
		if(ty==3)ti++;
	}
	for(i=1;i<=it;i++){
		if(-1==r[i])r[i]=ti;
		if(l[i]<=r[i])add(1,1,ti,l[i],r[i],i);
	}
	vector<int> v(m+1);
	get(1,1,ti,v);
	for(i=1;i<=ti;i++)cout<<res[i]<<'\n';
}