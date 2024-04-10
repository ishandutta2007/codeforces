#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		string s,res;
		cin>>s;
		n=s.size();
		for(i=n-2;i>=0;i--){
			k=s[i]+s[i+1]-2*'0';
			if(k>=10){
				res=s.substr(0,i)+to_string(k)+s.substr(i+2);
				goto aaa;
			}
		}
		
		k=s[0]+s[1]-2*'0';
		res=to_string(k)+s.substr(2);
		aaa:;
		cout<<res<<'\n';
	}
}