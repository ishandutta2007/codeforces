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

int c[110][110];

signed main(){
	int n;
	scanf("%d",&n);
	int ai=0,aj=0,bi=0,bj=1;
	for(int i=0;i<n*n;i++){
		int no;
		scanf("%d",&no);
		if(no!=1){
			if(ai<n){
				printf("%d %d %d\n",1,ai+1,aj+1);
				c[ai][aj]=1,aj+=2;
				if(aj>=n)ai++,aj=(ai&1);
			}
			else{
				int u=5-no;
				printf("%d %d %d\n",u,bi+1,bj+1);
				c[bi][bj]=u,bj+=2;
				if(bj>=n)bi++,bj=(bi&1)^1;
			}
		}
		else{
			if(bi<n){
				printf("%d %d %d\n",2,bi+1,bj+1);
				c[bi][bj]=2,bj+=2;
				if(bj>=n)bi++,bj=(bi&1)^1;
			}
			else{
				printf("%d %d %d\n",3,ai+1,aj+1);
				c[ai][aj]=3,aj+=2;
				if(aj>=n)ai++,aj=(ai&1);
			}
		}
		fflush(stdout);
	}
}