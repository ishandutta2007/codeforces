#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,pos[N];
void prepare(){
    scanf("%d",&n);
    int x;
    FOR(i,1,n){
        scanf("%d",&x);
        pos[x]=i;
    }
}
int solve(){
    int ans=0;
    for(int i=1;i<=n;i++){
        int st=i;
        while (pos[i+1]>=pos[i]) i++;
        ans=max(ans,i-st+1);
    }
    return n-ans;
}
int main(){
    prepare();
    cout<<solve();
}