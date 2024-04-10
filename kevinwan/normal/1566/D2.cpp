#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef array<ll,21> farray;

const int mn = 8e5+10;
const ll mod = 1e9+7;

int a[mn],o[mn],sn[mn];
bool av[300][300];

int t[mn];
void fix(int l,int r,int m){
	copy(o+l,o+r,t);
	sort(t,t+r-l);
	//cerr<<l<<" "<<r<<endl;
	int rl=l/m,rr=(r-1)/m;
	int cur=0;
	for(int i=rl;i<=rr;i++){
		for(int j=m-1;j>=0;j--){
			if(i*m+j<l||i*m+j>=r)continue;
			o[i*m+j]=t[cur++];
		}
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	iota(o,o+m*n,0);
	sort(o,o+m*n,[](int i,int j){
		return a[i]<a[j];
	});
	int l=0;
	for(int i=1;i<=n*m;i++){
		if(a[o[i]]!=a[o[l]]||i==n*m){
			fix(l,i,m);
			l=i;
		}
	}
	for(int i=0;i<n*m;i++)sn[o[i]]=i;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)av[i][j]=0;
	int ans=0;
	for(int i=0;i<n*m;i++){
		int r=sn[i]/m,c=sn[i]%m;
		for(int j=0;j<c;j++)ans+=av[r][j];
		av[r][c]=1;
	}
	printf("%d\n",ans);
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	for(int tcc=1;tcc<=tc;++tcc){
		int temp;
		solve();
	}
}