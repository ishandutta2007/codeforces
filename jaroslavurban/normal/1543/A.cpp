#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	ll a,b;cin>>a>>b;
	if(a==b){
		cout<<"0 0\n";return;
	}
	if(a>b)swap(a,b);
	ll diff=b-a;
	ll less=b/diff;
	cout<<diff<<" "<<min(abs(b-less*diff),abs(b-(less+1)*diff))<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}