#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("F.inp","r",stdin)
#define OUTPUT freopen("F.out","w",stdout)
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
const int N=1e6+10;

int h[N],f[N];
int main(){
    int n,x;
    scanf("%d",&n);
    while (n--){
        scanf("%d",&x);
        h[x]++;
    }
    FORD(i,N-1,1){
        for(int j=i+i;j<N;j+=i) f[i]=max(f[i],f[j]);
        f[i]+=h[i];
    }
    cout<<f[1];
}