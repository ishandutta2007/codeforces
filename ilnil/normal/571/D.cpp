#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+5;
int n,m,x,y,qs,n1,n2;
int f[N],f2[N],si[N],cl[N];
int d[N],ds;
ll su[N],ans[N];
char c;
vector<P>Q[N];
struct nod{
	char c;int x,y;
}a[N/2+1];
int F(int x){
	for(;x!=f[x];x=f[x])d[++ds]=x;
	ll s=0;
	for(;ds;--ds){
		s+=su[d[ds]];
		f[d[ds]]=x;
		su[d[ds]]=s;
	}
	return x;
}
int F2(int x){
	for(;x!=f2[x];x=f2[x])d[++ds]=x;
	int s=0;
	for(;ds;--ds){
		s=max(s,cl[d[ds]]);
		f2[d[ds]]=x;
		cl[d[ds]]=s;
	}
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;n1=n2=n;
	fo(i,1,n)f[i]=f2[i]=i,si[i]=1;
	fo(i,1,m){
		cin>>c>>x;
		if(c=='U'){
			cin>>y;
			x=F(x);y=F(y);++n1;
			f[x]=f[y]=f[n1]=n1;
			si[n1]=si[x]+si[y];
		}else
		if(c=='M'){
			cin>>y;
			x=F2(x);y=F2(y);++n2;
			f2[x]=f2[y]=f2[n2]=n2;
		}else
		if(c=='A'){
			x=F(x);
			su[x]+=si[x];
		}else
		if(c=='Z'){
			x=F2(x);
			cl[x]=i;
		}else{
			F(x);
			ans[++qs]=su[x]+su[x==f[x]?0:f[x]];
			F2(x);
			Q[max(cl[x],cl[f2[x]])].push_back(P(qs,x));
		}
		a[i]=(nod){c,x,y};
	}
	fo(i,1,n*2)su[i]=si[i]=0;
	fo(i,1,n)f[i]=i,si[i]=1;n1=n;
	fo(i,1,m){
		c=a[i].c;x=a[i].x;y=a[i].y;
		if(c=='U'){
			x=F(x);y=F(y);++n1;
			f[x]=f[y]=f[n1]=n1;
			si[n1]=si[x]+si[y];
		}else
		if(c=='A'){
			x=F(x);
			su[x]+=si[x];
		}
		for(P j:Q[i]){
			F(j.se);
			ans[j.fi]-=su[j.se]+su[f[j.se]==j.se?0:f[j.se]];
		}
	}
	fo(i,1,qs)cout<<ans[i]<<endl;
}