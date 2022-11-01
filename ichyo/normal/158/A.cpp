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
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	REP(i,n)cin>>v[i];
	if(v[k-1] > 0){
		int ans = k;
		for(int i = k; i < n; i++){
			if(v[i]==v[i-1]) ans++;
			else break;
		}
		cout<<ans<<endl;
	}else{
		int ans = 0;
		for(int i = k-2; i>=0; i--){
			if(v[i]) ans ++;
		}
		cout<<ans<<endl;
	}
	return 0;
}