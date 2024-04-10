#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
string s,s1,s2,s3;

int main() {
	//ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>s;
		if(!m){
			cout<<1<<'\n';continue;
		}
		s1=s;
		reverse(s1.begin(),s1.end());
		s2=s1+s;
		s3=s+s1;
		if(s2==s3){
			cout<<1<<'\n';
		}
		else{
			cout<<2<<'\n';
		}
	}
}