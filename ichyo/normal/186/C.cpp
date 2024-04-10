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
Matrix operator^(const Matrix &a,ll v){
	if(v==0)return make_E(a.size());
	Matrix res=(a*a)^(v/2);
	if(v&1)res=res*a;
	return res;
}

int main(){
  ll n;
  while(cin>>n){
    Matrix m(2, Array(2));
    m[0][0] = 3; m[0][1] = 1;
    m[1][0] = 1; m[1][1] = 3;
    Matrix ans = m ^ n;
    cout<<ans[0][0]<<endl;
  }
  return 0;
}