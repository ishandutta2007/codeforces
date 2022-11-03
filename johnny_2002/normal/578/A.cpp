#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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

double solve(int x,int y){
    double ans;
    if (x==y) return y;
    int g=int((x-y+.0)/y);
    if (g&1) g--;
    ans=(x-y+.0)/g;
    g=int((x+y+.0)/y);
    if (g&1) g--;
    ans=min(ans,(x+y+.0)/g);
    return ans;
}
int main(){
    int x,y;
    cin>>x>>y;
    if (x<y){
        printf("-1");
        return 0;
    }
    printf("%.9f",solve(x,y));
}