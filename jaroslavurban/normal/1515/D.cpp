#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,l,r;cin>>n>>l>>r;
		vector<vector<int>>cnt(n,vector<int>(2));
		for(int i=0;i<l;++i){
			int c;cin>>c;++cnt[c-1][0];
		}
		for(int i=0;i<r;++i){
			int c;cin>>c;++cnt[c-1][1];
		}
		int d[2]={},L[2]={};
		for(int i=0;i<n;++i)d[cnt[i][1]>cnt[i][0]]+=abs(cnt[i][0]-cnt[i][1])/2,L[cnt[i][1]>cnt[i][0]]+=(cnt[i][0]+cnt[i][1])&1;
		int mn=min(L[0],L[1]);
		int res=d[0]+d[1];
		res+=mn;
		for(int i=0;i<2;++i)res+=max(0,(L[i]-mn)-2*d[!i])+min(L[i]-mn,2*d[!i])/2;
		cout<<res<<"\n";
	}
}