#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("f.inp","r",stdin)
#define OUTPUT freopen("f.out","w",stdout)
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
const int N=2e5+10;

int b[N],n,a[N],p[N],ans[N];
bool comp(int x,int y){
    return a[x]<a[y];
}
void add(int x,int v){
    while (x<=n){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int x){
    int tmp=0;
    while (x){
        tmp+=b[x];
        x-=x&-x;
    }
    return tmp;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,comp);
    FOR(i,1,n){
        int next=i;
        while (next<n&&a[p[next+1]]==a[p[i]]) next++;
        FOR(j,i,next){
            int x=p[j];
            for(int k=1;k<n&&1LL*k*(x-1)+2<=n;k++){
                int L=k*(x-1)+2,R=min(n,k*x+1);
                //printf("%d %d %d %d\n",x,k,L,R);
                ans[k]+=get(R)-get(L-1);
            }
        }
        FOR(j,i,next) add(p[j],1);
        i=next;
    }
    REP(i,1,n) printf("%d ",ans[i]);
}