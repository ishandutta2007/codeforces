#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 110;
db p[N];
int n,x;

typedef vector<vector<db> > MM;
MM operator * (const MM a,const MM b){
    int L = sz(a);MM r(L,vector<db>(L,0));
    rep(i,0,L) r[i][i] = 0;
    rep(i,0,L) rep(j,0,L) rep(k,0,L) r[i][j] += a[i][k] * b[k][j];
    return r;
}
MM operator ^ (MM a,ll t){
    MM r(sz(a),vector<db>(sz(a),0.));
    rep(i,0,sz(a)) r[i][i] = 1;
    for(;t;t>>=1,a=a*a) if(t&1) r=r*a;
    return r;
}


int main(){
    scanf("%d%d",&n,&x);
    rep(i,0,x + 1) scanf("%lf",p + i);
    MM a(128 , vector<db>(128 , 0));
    rep(i,0,128) rep(j,0,x + 2) a[i][i^j] = p[j];
    a = a ^ n;
    printf("%.12lf\n",1 - a[0][0]);
    return 0;
}