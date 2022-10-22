#include <bits/stdc++.h>
using namespace std;
 
mt19937_64 rng(time(0));
const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
 
const int mn=2e5+10;
int test(vector<int>a,vector<int>b){
	printf("? %d %d\n",a.size(),b.size());
	for(int x:a)printf("%d ",x);
	printf("\n");
	for(int x:b)printf("%d ",x);
	printf("\n");
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
void report(vector<int>ans){
	printf("! %d ",ans.size());
	for(int x:ans)printf("%d ",x);
	printf("\n");
	fflush(stdout);
}
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		vi tst;
		for(int j=i+1;j<=n;j++)tst.push_back(j);
		int res = test(tst,{i});
		if(res){
			int l=1,r=i;
			while(l<r){
				int mid = (l+r)>>1;
				vi vl;
				for(int j=l;j<=r;j++){
					if(j<=mid)vl.push_back(j);
				}
				int res=test(vl,{i});
				if(res)r=mid;
				else l=mid+1;
			}
			int bad=-1;
			if(l==r){
				bad=l;
			}
			vi ans;
			for(int j=1;j<i;j++)if(j!=bad)ans.push_back(j);
			for(int j=i+1;j<n;j++){
				int r=test({i},{j});
				res-=r;
				if(!r)ans.push_back(j);
			}
			if(!res)ans.push_back(n);
			report(ans);
			return;
		}
	}
}
 
signed main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}
}