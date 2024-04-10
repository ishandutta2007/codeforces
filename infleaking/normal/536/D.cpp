#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2010,M=2e5+10;
map<ll,ll> p1,p2;
ll f[N][N][2];
ll s1[N],s0[N],n,m;
ll a[N][N],q[N][N],S,T;
ll d1[N],d2[N],d[N];
ll w[M],ne[M],la[N],len[M],t,p[N];
ll px[N],py[N],t0[N],tag[N];
void link(int x,int y,int z){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
	len[t]=z;
}
set<pair<ll,int> > h;
void dij(int S,ll *s){
	for (int i=1;i<=n;i++)s[i]=1e18;
	s[S]=0;
	for (int i=1;i<=n;i++)h.insert(make_pair(s[i],i));
	for (int u=1;u<=n;u++){
		int x=h.begin()->second;
		h.erase(h.begin());
		for (int y=la[x];y;y=ne[y]){
			int z=w[y];
			if (s[z]>s[x]+len[y]){
				h.erase(make_pair(s[z],z));
				s[z]=s[x]+len[y];
				h.insert(make_pair(s[z],z));
			}
		}
	}
}
void make1(ll *a){	
	memcpy(d1,a,sizeof d1);
	sort(d1+1,d1+n+1);
	for (int i=1;i<=n;i++)p1[d1[i]]=i;
	for (int i=1;i<=n;i++)a[i]=p1[a[i]];
	p1.clear();
}
ll sum(ll l1,ll r1,ll l2,ll r2){
	l1=max(l1,1LL),l2=max(l2,1LL);
	r1=min(r1,n),r2=min(r2,n);
	l1--,l2--;
	return q[r1][r2]-q[r1][l2]-q[l1][r2]+q[l1][l2];
}
int main(){
	cin>>n>>m>>S>>T;
	for (int i=1;i<=n;i++)scanf("%lld",&p[i]);
	for (int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		link(x,y,z);
		link(y,x,z);
	}
	dij(S,px);
	dij(T,py);
	make1(px);
	make1(py);
	for (int i=1;i<=n;i++)q[px[i]][py[i]]+=p[i],a[px[i]][py[i]]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)q[i][j]+=q[i-1][j]+q[i][j-1]-q[i-1][j-1];
	for (int i=0;i<=n;i++){
		s0[i]=t0[i]=sum(1,n,i+1,n);
		s1[i]=sum(i+1,n,1,n);
	}
	for (int i=0;i<=n;i++)if (a[n][i])tag[i]=1;
	for (int i=n-1;i>=0;i--){
		ll _s1=s1[i];
		for (int j=n-1;j>=0;j--){
			f[i][j][0]=s0[j]-sum(1,i,j+1,n);
			f[i][j][1]=s1[i]-sum(i+1,n,1,j);
			t0[j]=max(t0[j],-f[i][j][1]+sum(1,i,j+1,n));
			_s1=max(_s1,-f[i][j][0]+sum(i+1,n,1,j));
			if (tag[j])s1[i]=_s1;
		}
		for (int j=0;j<=n;j++){
			if (a[i][j]){
				tag[j]=1;
				for (int j1=0;j1<j;j1++)s0[j1]=t0[j1];
			}
		}
	}
	if (f[0][0][0]==0)
		cout<<"Flowers"<<endl;
	if (f[0][0][0]>0)
		cout<<"Break a heart"<<endl;
	if (f[0][0][0]<0)
		cout<<"Cry"<<endl;
}