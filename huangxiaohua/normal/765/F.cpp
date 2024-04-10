#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000005
int i,j,k,n,m,t,f[100500],res[300500],a[100500];
vector<pair<int,int> >q[100500];

void add(int x,int y){
	for(;x;x-=(-x&x)){f[x]=min(f[x],y);}
}
int get(int x,int y=M){
	for(;x<=n;x+=(-x&x)){y=min(y,f[x]);}return y;
}

struct SB{
	#define md ((l+r)/2)
	int ls[3105000],rs[3105000],f[3105000],it=1;
	void add(int &id,int l,int r,int x,int w){
		if(!id)id=++it;
		if(l==r){f[id]=w;return;}
		if(x<=md)add(ls[id],l,md,x,w);
		else add(rs[id],md+1,r,x,w);
		f[id]=max(f[ls[id]],f[rs[id]]);
	}
	int get(int &id,int l,int r,int x,int y){
		if(!id)return 0;
		if(x<=l&&r<=y)return f[id];
		int ans=0;
		if(x<=md)ans=max(ans,get(ls[id],l,md,x,y));
		if(y>md)ans=max(ans,get(rs[id],md+1,r,x,y));
		return ans;
	}
}sb,sb2;

int main() {
	ios::sync_with_stdio(0);
	cin>>n;cin.tie(0);cout.tie(0);
	for(i=1;i<=n;i++){
		cin>>a[i];a[i]++;f[i]=1e9;
	}
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>j>>k;
		q[k].push_back({i,j});
	}
	for(i=1;i<=n;i++){
		j=sb.get(sb.f[1],1,M,1,a[i]);
		while(j){
			add(j,abs(a[i]-a[j]));
			if(a[i]==a[j])break;
			j=sb.get(sb.f[1],1,M,a[i]-(a[i]-a[j])/2,a[i]);
		}
		j=sb2.get(sb2.f[1],1,M,1,M-a[i]);
		while(j){
			add(j,abs(a[i]-a[j]));
			if(a[i]==a[j])break;
			j=sb2.get(sb2.f[1],1,M,M-a[i]-(a[j]-a[i])/2,M-a[i]);
		}
		sb.add(sb.f[1],1,M,a[i],i);
		sb2.add(sb2.f[1],1,M,M-a[i],i);
		for(auto [x,y]:q[i]){
			res[x]=get(y);
		}
	}
	for(i=1;i<=t;i++)cout<<res[i]<<'\n';
}