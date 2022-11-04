#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int a[N];
int n;
unordered_map<int,ll>sm;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n;
		sm.clear();
		for(int i=0;i<n;++i)cin>>a[i];
		ll res=0;
		for(int i=0;i<n;++i){
			res+=sm[a[i]]*(n-i);
			sm[a[i]]+=i+1;
		}
		cout<<res<<"\n";
	}
}