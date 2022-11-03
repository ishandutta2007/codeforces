#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;
int xa,ya,yb,xb;
string solve(){
    if (xa+ya<=max(xb,yb)) return "Polycarp";
    if (xa<=xb&&ya<=yb) return "Polycarp";
    return "Vasiliy";
}
int main(){
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    cout<<solve();
}