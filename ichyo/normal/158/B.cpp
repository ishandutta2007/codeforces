#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
	int n; cin>>n;
	int a[4] = {};
	REP(i,n){
		int t; cin>>t;
		a[t-1] ++;
	}
	int ans = 0;
	while(n){
		int rest = 4;
		for(int i = 3; i>=0; i--){
			while(a[i] && (i+1)<=rest){
				a[i]--;
				n--;
				rest -= i+1;
			}
		}
		ans++;
	}
	cout<<ans<<endl;

	return 0;
}