#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rv(a) reverse(a.begin(),a.end())
using namespace std;
const int N=3005,K=11;
int r,c,n,k,x,y,d[N],ds;
int L[N],R[N],le[K],ri[K],gl,gr;
vector<int>a[N];
P b[N];
ll ans,cnt;
bool bz[N];
int work(){
	int s=0,las=0;
	fo(i,1,ds-k+1)
		s+=(b[d[i]].fi-las)*(c-b[d[i+k-1]].fi+1),las=b[d[i]].fi;
	return s;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>r>>c>>n>>k;
	fo(i,1,n)cin>>b[i].se>>b[i].fi;
	sort(b+1,b+n+1);
	fo(i,1,n)a[b[i].se].push_back(i);
	fd(i,1,r){
		for(int j:a[i])bz[j]=1;
		int las=0;ds=0;
		fo(j,1,n)if(bz[j])L[j]=las,R[las]=j,las=j,d[++ds]=j;
		cnt=work();
		fd(j,i,r){
			ans+=cnt;
			for(int l:a[j]){
				gl=gr=0;
				for(int p=L[l];p&&gl<=k;p=L[p])le[++gl]=p;
				for(int p=R[l];p&&gr<=k;p=R[p])ri[++gr]=p;
				ds=0;
				fd(i,1,gl)d[++ds]=le[i];
				d[++ds]=l;
				fo(i,1,gr)d[++ds]=ri[i];
				cnt-=work();
				ds=0;
				fd(i,1,gl)d[++ds]=le[i];
				fo(i,1,gr)d[++ds]=ri[i];
				cnt+=work();
				L[R[l]]=L[l];R[L[l]]=R[l];
			}
		}
	}
	cout<<ans;
}