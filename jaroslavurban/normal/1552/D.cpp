#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

struct A{
	array<int,5>ranks;
	int id;
	bool issup(A&a){
		int btr=0;
		for(int i=0;i<5;++i)btr+=ranks[i]<a.ranks[i];
		return btr>=3;
	}
};

void ProGamerMove(){
	int n;cin>>n;
	vector<int>a(n);
	for(auto&v:a)cin>>v;
	for(int m=0;m<1<<n;++m){
		for(int j=0;j<n;++j)if(!(m&1<<j)){
			for(int s=m;s>=0;s=(s-1)&m){
				int sm=0;
				for(int k=0;k<n;++k)if(s&1<<k)sm+=a[k];
				else if(m&1<<k)sm-=a[k];
				if(sm==a[j]){cout<<"YES\n";return;}
				if(s==0)break;
			}
		}
	}
	cout<<"NO\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}