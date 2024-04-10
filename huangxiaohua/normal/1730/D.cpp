#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[125][125];
string s1,s2;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	
	while(t--){
		cin>>n>>s1>>s2;
		s1="$"+s1;s2="$"+s2;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++){
			f[min(s1[i],s2[n+1-i])][max(s1[i],s2[n+1-i])]++;
		}
		for(i='a';i<='z';i++){
			for(j=i+1;j<='z';j++){
				if(f[i][j]&1){
					cout<<"NO\n";goto aaa;
				}
			}
		}
		k=0;
		for(i='a';i<='z';i++){
			k+=(f[i][i]&1);
		}
		if(n%2){
			if(k!=1){
				cout<<"NO\n";goto aaa;
			}
		}
		else if(k){
			cout<<"NO\n";goto aaa;
		}
		cout<<"YES\n";
		aaa:;
	}
}