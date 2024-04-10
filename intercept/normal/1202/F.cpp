#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
using namespace std;
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int ans=0;
	for(int l=1,r;l<=n+m;l=r+1){
		r=(n+m)/((n+m)/l);
		int k=(n+m)/l;
		int lx=(n-1)/(k+1)+1,ly=n/k;
		int rx=(m-1)/(k+1)+1,ry=m/k;
		if(ly==0||ry==0||lx>ly||rx>ry)continue;
		int L=lx+rx,R=ly+ry;
		ans+=min(R,r)-max(L,l)+1;
	}
	cout<<ans<<endl;
	return 0;
}