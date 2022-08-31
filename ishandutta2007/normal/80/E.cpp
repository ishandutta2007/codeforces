#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()
typedef pair<long long, long long> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

VI a;
VVI e;
VI u;
PII go (int x){
    if (u[x] || !a[x])     return PII();//if already visited or stones left is zero return null
    u[x] = 1;
    VPII b;
    REP(i,e[x].size()){
       b.pb(go(e[x][i]));//visit all neb nodes and collect answers in b
       if(b.back() == PII()) b.pop_back();
    }
    PII res;res.X ++; a[x]--;
    SORT(b);REVERSE(b);
    REP(i,b.size()){if(a[x]){res.X+=b[i].X+1;a[x]--;}}//use only greater nebs by ans
    REP(i,b.size()){
       int v = min(a[x],(int)b[i].Y);//if any neb has lesser stones than a[x] eat up all those
       res.X+= v*2;
       a[x]-= v;
    }//in tree each node is going to be visited once so no harm in changing the original a itself
    res.Y = a[x];//cout << x << " " << b.size()<< " " << res.X << " " << res.Y << endl;
    return res;
}
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w+", stdout);
    int n;scanf ("%d", &n);
    a.resize(n);e.resize(n);u.resize(n);
    REP (i, n) scanf ("%d", &a[i]);
    int x, y;
    REP(i, n-1){
       scanf("%d%d",&x,&y);x--;y--;
       e[x].pb(y); e[y].pb(x);
    }
    int s;scanf("%d",&s);s--;
    a[s]++;PII res=go(s);
    cout<<res.X-1<<endl;
    return 0;
}