#include<bits/stdc++.h>
using namespace std;

string t;
int p[5001][5001];
int val[5001][5001];
int n;

int ans[5001];

int calc(int x, int y) {
	if(val[x][y]!=0) return val[x][y];
	if(!p[x][y]) return 0;
	if(x==y) return val[x][y]=1;
	
	int len=y-x+1;
	int ans=1;
	if(p[x][x+len/2-1] && p[y-len/2+1][y]) {
		int a=calc(x, x+len/2-1);
		int b=calc(y-len/2+1, y);
		ans=max(ans, min(a,b)+1);
	}
	//cerr<<x<<" "<<y<<" "<<ans<<"\n";
	return val[x][y]=ans;
}

int calcp(int x, int y){
	if(p[x][y]!=-1) return p[x][y];
	if(x==y) return p[x][y]=1;
	if(y==x+1 && t[x]==t[y]) return p[x][y]=1;
	
	return p[x][y]=(t[x]==t[y]&&calcp(x+1,y-1));
}



int main() {
	memset(p, -1, sizeof p);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>t;
	n=t.size();

	for(int i=0;i<n;++i) {
		for(int j=i;j<n;++j) {
			calcp(i,j);
		}
	}
	for(int i=0;i<n;++i) {
		for(int j=i;j<n;++j) {
			calc(i,j);
		}
	}
	
	for(int i=0;i<n;++i) {
		for(int j=i;j<n;++j) {
			if(val[i][j]<=n) ans[val[i][j]]++;
		}
	}
	
	for(int i=n-1;i>=1;i--) ans[i]+=ans[i+1];
	for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
	
	
	
}