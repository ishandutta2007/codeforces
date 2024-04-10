#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll res;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s;s=" "+s;
		res=0;
		for(i=1;i<=n;i++){
			for(j=i;j<=n;j+=i){
				if(s[j]=='1')break;
				if(s[j]=='2')continue;
				s[j]='2';res+=i;
			}
		}
		cout<<res<<'\n';
	}
}