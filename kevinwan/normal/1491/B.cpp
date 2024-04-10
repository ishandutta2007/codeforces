#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int num=0;
int a[100010];

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,u,v;
		scanf("%d%d%d",&n,&u,&v);
		int lv=-1;
		bool line=1,bl=1;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(lv>0){
				if(x!=lv)line=0;
				if(abs(x-lv)>1)bl=0;
			}
			lv=x;
		}
		if(line)printf("%d\n",v+min(u,v));
		else if(bl)printf("%d\n",min(u,v));
		else printf("0\n");
	}
}