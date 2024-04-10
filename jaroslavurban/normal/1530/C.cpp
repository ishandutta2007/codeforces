#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>a(n),b(n);
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cin>>b[i];
	sort(a.begin(),a.end());
	sort(b.rbegin(),b.rend());
	int i=0,j=n-n/4;
	int mysm=accumulate(a.begin(),a.end(),0);
	int hism=accumulate(b.begin(),b.end(),0);
	for(;i<n/4;++i)mysm-=a[i];
	for(int k=j;k<n;++k)hism-=b[k];
	int res=0;
	for(;mysm<hism;){
		++n;++res;
		a.push_back(100);
		mysm+=100;
		b.push_back(0);
		for(;i<n/4;++i)mysm-=a[i];
		for(;j<n-n/4;++j)hism+=b[j];
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}