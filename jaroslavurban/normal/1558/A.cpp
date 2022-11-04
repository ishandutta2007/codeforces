#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int a,b;cin>>a>>b;
	int n=a+b;
	vector<int>pos(n+1);
	for(int it=0;it<2;++it){
		int serve=(n+1)/2;
		if(a<=serve){
			for(int i=serve-a;i<=min(n,2*a+serve-a);i+=2)pos[i]=pos[n-i]=true;
		}
		if(n&1){
			--serve;
			if(a<=serve){
				for(int i=serve-a;i<=min(n,2*a+serve-a);i+=2)pos[i]=pos[n-i]=true;
			}
		}
		swap(a,b);
	}
	cout<<accumulate(pos.begin(),pos.end(),0)<<"\n";
	for(int i=0;i<=n;++i)if(pos[i])cout<<i<<" ";cout<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}