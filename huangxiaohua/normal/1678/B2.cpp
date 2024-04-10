#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,f[1005000][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		string s;
		cin>>n>>s;
		s="X"+s;
		sb=0;
		memset(f,1,n*8+50);
		f[0][0]=f[0][1]=0;
		for(i=2;i<=n;i+=2){
			if(s[i]!=s[i-1]){
				sb++;
			}
			if((s[i]&1)||(s[i-1]&1)){
				f[i][1]=min(f[i-2][0]+1,f[i-2][1]);
			}
			if(!(s[i]&1)||!(s[i-1]&1)){
				f[i][0]=min(f[i-2][0],f[i-2][1]+1);
			}
		}
		cout<<sb<<' '<<min(f[n][0],f[n][1])+1<<'\n';
	}
}