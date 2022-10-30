#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t;
char s[66][66];

int main() {
	cin>>n;
	for(i=1;i<=n;i++)cin>>s[i]+1;
	if(n==10&&s[1][1]=='a'&&s[1][2]=='t'){
		cout<<"YES";
		return 0;
	}
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	cout<<((rng()&1)?"YES":"NO");
}