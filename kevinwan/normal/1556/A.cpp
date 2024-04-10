#include <bits/stdc++.h>
using namespace std;
 
const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=4e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=31607;

int solve(int a,int b) {
	int s=a+b;
	if(s%2) return -1;
	if(a==0&&b==0) return 0;
	if(a==b) return 1;
	return 2;
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",solve(a,b));
	}
}