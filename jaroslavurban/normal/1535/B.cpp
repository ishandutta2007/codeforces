#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a.begin(),a.end(),[&](int x,int y){
		return (x&1)<(y&1);
	});
	int res=0;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			res+=__gcd(a[i],2*a[j])!=1;
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}