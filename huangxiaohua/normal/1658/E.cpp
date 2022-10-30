#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,px[4005000],py[4005000],l1,r1,l2,r2,a,b;
char res[2050][2050];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>k;
			px[k]=i+j;
			py[k]=i-j;
		}
	}
	l1=l2=-1e9;r1=r2=1e9;
	for(i=n*n;i>=1;i--){
		a=(px[i]+py[i])/2;b=(px[i]-py[i])/2;
		if(l1<=px[i]&&px[i]<=r1&&l2<=py[i]&&py[i]<=r2){
			l1=max(l1,px[i]-m);
			r1=min(r1,px[i]+m);
			l2=max(l2,py[i]-m);
			r2=min(r2,py[i]+m);
			res[a][b]='M';
		}
		else res[a][b]='G';
	}
	for(i=1;i<=n;i++)cout<<res[i]+1<<'\n';
}