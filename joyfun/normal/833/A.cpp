// #include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

int n,a,b;
set<int> S;


int main(){
    rep(i,1,1001) S.insert(i*i*i);
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d%d",&a,&b);
        int g=__gcd(a,b);
        a/=g;b/=g;
        if(g%a!=0){
            puts("No");
            continue;
        }
        g/=a;
        if(g%b!=0){
            puts("No");
            continue;
        }
        g/=b;
        puts(S.count(g) ? "Yes" : "No");
    }
    return 0;
}