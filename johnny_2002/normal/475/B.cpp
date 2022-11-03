#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
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
const int N=500;

int n,m,h[N];
vector <int> a[N];
string s;
void prepare(){
    cin>>n>>m>>s;
    REP(i,0,n) if (s[i]=='<'){
        REP(j,1,m) a[i*m+j].push_back(i*m+j-1);
    }else REP(j,0,m-1) a[i*m+j].push_back(i*m+j+1);
    cin>>s;
    REP(i,0,m) if (s[i]=='v')
        REP(j,0,n-1) a[j*m+i].push_back((j+1)*m+i);
        else REP(j,1,n) a[j*m+i].push_back((j-1)*m+i);
}
bool BFS(int x){
    memset(h,0,sizeof(h));
    queue <int> q;
    q.push(x);
    while (!q.empty()){
        int cx=q.front();q.pop();
        REP(i,0,a[cx].size()) if (h[a[cx][i]]==0)
            h[a[cx][i]]=1,q.push(a[cx][i]);
    }
    REP(i,0,n*m) if (h[i]==0) return false;
    return true;
}
void solve(){
    bool ok=true;
    REP(i,0,n*m) if (!BFS(i)) ok=false;
    if (ok) printf("YES");else printf("NO");
}
int main(){
    prepare();
    solve();
}