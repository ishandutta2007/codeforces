#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	ll c,d;cin>>c>>d;
	if(c==d){
		cout<<(c!=0)<<"\n";
		return;
	}
	if(abs(c-d)&1){cout<<"-1\n";return;}
	cout<<"2\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}