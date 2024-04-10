#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define bit bitset<N>
using namespace std;
const int N=155;
int n,m,ans,d[N],h[N],ds;
vector<int>e[N];
struct nod{int a,b,d;}a[N];
struct mat{bit a[N];}f,E,f2;
bit b;
bool cmp(nod a,nod b){return a.d<b.d;}
mat operator*(const mat&a,const mat&b){
	mat c;
	fo(i,1,n)c.a[i].reset();
	fo(i,1,n)fo(j,1,n)if(a.a[i][j])c.a[i]|=b.a[j];
	return c;
}
void ksm(int x){
	if(!x){f2=E;return;}
	if(x==1){f2=f;return;}
	ksm(x>>1);
	f2=f2*f2;
	if(x&1)f2=f2*f;
}
bit operator*(const bit &a,const mat &b){
	bit c;c.reset();
	fo(i,1,n)if(a[i])c|=b.a[i];
	return  c;
}
int main(){
	cin>>n>>m;ans=2e9;
	fo(i,1,m)cin>>a[i].a>>a[i].b>>a[i].d;
	sort(a+1,a+m+1,cmp);
	b[1]=1;
	fo(i,1,n)E.a[i][i]=1;
	fo(i,1,m){
		int dt=a[i].d-a[i-1].d;
		ksm(dt);
		b=b*f2;
		if(b[n]){ans=min(ans,a[i].d);break;}
		e[a[i].a].push_back(a[i].b);
		f.a[a[i].a][a[i].b]=1;
		fo(j,1,n)h[j]=-1;
		ds=0;
		fo(j,1,n)if(b[j])d[++ds]=j,h[j]=0;
		for(int l=0,x;x=d[++l],l<=ds;)
			for(int t:e[x])if(h[t]==-1)h[t]=h[x]+1,d[++ds]=t;
		if(h[n]>-1)ans=min(ans,a[i].d+h[n]);
	}
	if(ans==2e9)cout<<"Impossible";else cout<<ans;
}