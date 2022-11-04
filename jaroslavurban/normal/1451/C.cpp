#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s;
int l,r;
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n,k;cin>>n>>k;
		string a,b;cin>>a>>b;
		vector<int>cnta(300),cntb(300);
		for(int i=0;i<n;++i)++cnta[a[i]];
		for(int i=0;i<n;++i)++cntb[b[i]];
		bool pos=true;
		for(int i=1;i<300;++i){
			cnta[i]+=cnta[i-1]-cntb[i-1];
			if(cnta[i]<cntb[i])pos=false;
			if((cnta[i]-cntb[i])%k)pos=false;
		}
		if(pos)cout<<"Yes\n";
		else cout<<"No\n";
	}
}