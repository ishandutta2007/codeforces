#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
string s1,s2,s3;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>s1>>s2;
		set<char> s;
		for(i=0;i+m<n;i++){
			s.insert(s1[i]);
		}
		s3=s1.substr(n-m);
		if(s3==s2){
			cout<<"YES\n";goto aaa;
		}
		for(auto i:s){
			s3[0]=i;
			if(s3==s2){
				cout<<"YES\n";goto aaa;
			}
		}
		cout<<"NO\n";
		aaa:;
	}
}