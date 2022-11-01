#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define P pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=520;
int k,t,all,ans;
ll a[N][N],a2[N][N];
vector<P>b;
int main(){
	ios::sync_with_stdio(0);
	cin>>k;all=1<<k;
	fo(i,0,all-1)fo(j,0,all-1)cin>>a[i][j];
	cin>>t;b.resize(t);
	fo(i,0,t-1)cin>>b[i].fi>>b[i].se;
	fd(i,0,t-1)b[i].fi=(b[i].fi-b[0].fi+all)&(all-1),b[i].se=(b[i].se-b[0].se+all)&(all-1);
	fo(o,1,k){
		fo(i,0,all-1)fo(j,0,all-1){
			a2[i][j]=0;
			for(P l:b)
				a2[i][j]^=a[(i-l.fi+all)&(all-1)][(j-l.se+all)&(all-1)];
		}
		memcpy(a,a2,sizeof a);
		for(P &l:b)l.fi=l.fi*2&(all-1),l.se=l.se*2&(all-1);
	}
	fo(i,0,all-1)fo(j,0,all-1)ans+=a[i][j]>0;
	cout<<ans;
}