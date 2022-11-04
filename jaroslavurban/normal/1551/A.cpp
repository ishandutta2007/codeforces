#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	int t=n/3;
	if(n%3==0){cout<<t<<" "<<t<<"\n";return;}
	if(n%3==1){cout<<t+1<<" "<<t<<"\n";return;}
	if(n%3==2){cout<<t<<" "<<t+1<<"\n";return;}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}