#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=0;

int n;
ll x,y;
void solve(ll x,ll y){
    ll ans=0;
    int idx=0;
    while ((1LL<<idx)<=y) idx++;
    ans=(1LL<<idx)-1;
    while (ans>y){
        FORD(i,idx-1,0) if ((ans&(1LL<<i))&&(ans^(1LL<<i))>=x) {
            ans^=(1LL<<i);
            break;
        }
    }
    printf("%I64d\n",ans);
}
int main(){
    scanf("%d",&n);
    while (n--){
        scanf("%I64d%I64d",&x,&y);
        solve(x,y);
    }
}