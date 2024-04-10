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
typedef vector<ll> Array;
typedef vector<Array> Matrix;
Matrix operator*(const Matrix &a,const Matrix &b){
	int V=a.size();
	Matrix res(V,Array(V,0));
	REP(i,V){
		REP(j,V){
			REP(k,V){
				res[i][j]+=a[i][k]*b[k][j];
				res[i][j]%=MOD;
			}
		}
	}
	return res;
}
Matrix make_E(int V){
	Matrix res(V,Array(V,0));
	REP(i,V){
		res[i][i]=1;
	}
	return res;
}
Matrix operator^(const Matrix &a,int v){
	if(v==0)return make_E(a.size());
	Matrix res=(a*a)^(v/2);
	if(v&1)res=res*a;
	return res;
}
Array operator*(const Array& a, const Array& b){
  int N = a.size();
  Array res(N);
  REP(i, N)REP(j, i + 1){
    res[i] += a[j] * b[i - j];
    res[i] %= MOD;
  }
  return res;
}
Array make_EA(int N){
  Array res(N, 1LL);
  return res;
}
Array operator^(const Array &a,int v){
	if(v==0)return make_EA(a.size());
	Array res=(a*a)^(v/2);
	if(v&1)res=res*a;
	return res;
}
int main(){
  int n, k;
  while(cin>>n>>k){
    Array a(n);
    REP(i, n) cin>>a[i];
    if(k > 0) a = a * (make_EA(n) ^ (k - 1));
    debug(a.begin(), a.end());
  }
  return 0;
}