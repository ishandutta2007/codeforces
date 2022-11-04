#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int w,h;cin>>w>>h;
	int x[2],y[2];
	for(int i=0;i<2;++i)cin>>x[i]>>y[i];
	int w1=x[1]-x[0],h1=y[1]-y[0];
	int w2,h2;cin>>w2>>h2;
	if(w1+w2>w&&h1+h2>h){cout<<"-1\n";return;}
	int res=INT_MAX;
	if(h1+h2<=h)res=min(res,max(0,h2-y[0]));
	if(h1+h2<=h)res=min(res,max(0,y[1]-(h-h2)));
	if(w1+w2<=w)res=min(res,max(0,w2-x[0]));
	if(w1+w2<=w)res=min(res,max(0,x[1]-(w-w2)));
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}