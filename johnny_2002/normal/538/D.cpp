#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
//#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=60;

int n,a[N][N],ans[200][200],mark[N][N];
string s;
vector <ii> p;
bool debug(int x,int y){
    return (x==0&&y==-1);
}
bool check(int x,int y){
    return (x>0&&x<=n&&y>0&&y<=n);
}
int main(){
    cin>>n;
    FOR(i,1,n){
        cin>>s;
        FOR(j,1,n) {
            if (s[j-1]=='x') a[i][j]=1;
            else if (s[j-1]=='o') p.push_back(ii(i,j)),a[i][j]=-1;
        }
    }
    FOR(dx,-n,n)
        FOR(dy,-n,n){
            bool ok=1;
            for(auto cur:p){
                int nx=cur.X+dx,ny=cur.Y+dy;
                if (!check(nx,ny)) continue;
                if (a[nx][ny]==0) ok=0;
                //if (debug(dx,dy)) printf("%d %d %d %d\n",cur.X,cur.Y,nx,ny);
            }
            ans[n+dx][n+dy]=ok;
            if (ok){
                for(auto cur:p){
                    int nx=cur.X+dx,ny=cur.Y+dy;
                    if (check(nx,ny)) mark[nx][ny]=1;
                }
            }
            //printf("%d %d %d\n",dx,dy,ok);
        }
    FOR(i,1,n)
        FOR(j,1,n){
            if (a[i][j]!=-1&&mark[i][j]!=a[i][j]){
                printf("NO");
                return 0;
            }
        }
    printf("YES\n");
    FOR(i,1,2*n-1){
        FOR(j,1,2*n-1) if (i!=n||j!=n) printf("%c",ans[i][j]?'x':'.');
        else printf("o");
        ENDL;
    }
}