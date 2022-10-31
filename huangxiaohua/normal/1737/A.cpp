#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[666],NMSL;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		string s;
		cin>>n>>m>>s;
		NMSL=0;
		memset(f,0,sizeof(f));
		for(auto i:s)f[i]++;
		for(i=1;i<=m;i++){
			NMSL=0;
			for(j='a';;j++){
				NMSL++;
				if(NMSL>(n/m)){
					cout<<char(j);break;
				}
				if(!f[j]){
					cout<<char(j);break;
				}
				f[j]--;
			}
		}
		cout<<'\n';
	}
}