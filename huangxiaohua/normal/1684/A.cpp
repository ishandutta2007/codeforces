#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(s.size()>2){
			sort(s.begin(),s.end());
			cout<<s[0]<<'\n';
		}
		else{
			cout<<s[1]<<'\n';
		}
	}
}