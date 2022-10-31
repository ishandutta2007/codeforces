#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
string s;
int main() {
	ios::sync_with_stdio(0);
	cin>>s;
	n=s.size();
	s="X"+s;
	for(i=2;i<n;i++){
		if(s[i-1]=='.'||s[i]=='.'||s[i+1]=='.')continue;
		if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1]){
			cout<<"YES";return 0;
		}
	}
	cout<<"NO";
}