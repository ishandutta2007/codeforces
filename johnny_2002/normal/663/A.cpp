#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=1e2+10;

int n,m,a[N],ans[N];
string s;
void prepare(){
    n=1;
    a[1]=1;
    while (1){
        cin>>s;
        if (s[0]=='+') a[++n]=1;
        else if (s[0]=='-') a[++n]=-1;
        else if (s[0]=='?') continue;
        else break;
    }
    cin>>m;
}
void solve(){
    int nposi=count(a+1,a+n+1,1),nneg=n-nposi;
    int L=nposi-m*nneg,R=nposi*m-nneg;
    if (L>m||R<m){
        printf("Impossible");
        return;
    }
    printf("Possible\n");
    FOR(i,1,n) ans[i]=(a[i]==1)?1:m;
    int rem=m-L;
//    cout<<rem<<'\n';
    FOR(i,1,n) {
        int v=min(m-1,rem);
//        cout<<i<<" "<<rem<<" "<<v<<'\n';
        ans[i]+=a[i]*v;
        rem-=v;
    }
    printf("%d ",ans[1]);
    FOR(i,2,n) printf("%c %d ",(a[i]==1)?'+':'-',ans[i]);
    printf("= %d",m);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}