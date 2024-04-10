#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define abs(x)((x)>0?x:-(x))
#define P pair<int,int>
#define x first
#define y second
#define ll long long
#define V vector<int>
#define pb push_back
using namespace std;
const int N=1005;
int k,n,ans,d[N][10],fr[N][10],mi[N],w[N];
int nd[10],K;
map<P,int>A;
P a[N],b[10];
ll aa[N];
V o;
bool bz[N],ex[N],can[N];
int gcd(int x,int y){
	for(;y;y%=x)swap(x,y);
	return x;
}
bool cmp(int x,int y){return aa[x]<aa[y];}
bool cmp2(int x,int y){return d[K][nd[x]]<d[K][nd[y]];}
ll dis(P a){return (ll)a.x*a.x+(ll)a.y*a.y;}
bool work(V a,int st){
	if(!a.size())return 1;
	if(a.size()>k-st+1)return 0;
	sort(a.begin(),a.end(),cmp);
	V b,c,cl;
	b.clear();
	c.clear();
	fo(i,0,a.size()-2)b.pb(a[i]);
	fo(i,st,k)c.pb(i);
	K=a.back();
	sort(c.begin(),c.end(),cmp2);
	int z;
	bool ca=0;
	for(int i:c){
		cl.clear();
		ca=0;
		for(z=a.back();z=fr[z][nd[i]];)if(!ex[z])cl.pb(z),ex[z]=1,ca|=can[z];
		if(cl.size()+b.size()<=k-st&&!ca){
			for(int j:cl)b.pb(j);
			swap(nd[i],nd[st]);
			if(work(b,st+1)){
				bz[a.back()]=1;
				for(int j:cl)ex[j]=0;
				return 1;
			}
			swap(nd[i],nd[st]);
			for(int j:cl)b.pop_back();
		}
		for(int j:cl)ex[j]=0;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>k>>n;
	fo(i,1,k)cin>>b[i].x>>b[i].y;
	fo(i,1,n)cin>>a[i].x>>a[i].y;
	fo(i,1,k){
		A.clear();
		fo(j,1,n)w[j]=j,aa[j]=dis(P(a[j].x-b[i].x,a[j].y-b[i].y));
		sort(w+1,w+n+1,cmp);
		fo(k,1,n){
			int j=w[k];
			P c=P(a[j].x-b[i].x,a[j].y-b[i].y);
			int gc=gcd(abs(c.x),abs(c.y));
			c.x/=gc;c.y/=gc;
			if(A.count(c))fr[j][i]=A[c],d[j][i]=d[fr[j][i]][i]+1;
			A[c]=j;
		}
	}
	fo(i,1,n){
		mi[i]=d[i][1];
		fo(j,2,k)mi[i]=min(mi[i],d[i][j]);
	}
	fo(i,1,n)w[i]=i,aa[i]=mi[i];
	sort(w+1,w+n+1,cmp);
	o.resize(1);
	fo(i,1,k)nd[i]=i;
	fd(i,1,n){
		int j=w[i];
		if(mi[j]+1<=k&&!bz[j]){
			o[0]=j;ex[j]=1;
			work(o,1);
			if(!bz[j])can[j]=1;
			ex[j]=0;
		}
	}
	fo(i,1,n)if(bz[i])++ans;
	cout<<ans;
}