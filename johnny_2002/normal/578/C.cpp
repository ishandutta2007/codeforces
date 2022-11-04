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
const int N=2e5+10;
const double eps=1e-9;

int n,a[N];
double cal(double x){
    double ans=0,cur=0;
    FOR(i,1,n) {
        cur=max(.0,cur+a[i]-x);
        ans=max(ans,cur);
    }
    cur=0;
    FOR(i,1,n){
        cur=max(.0,cur+x-a[i]);
        ans=max(ans,cur);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    double L=-1e4,R=1e4;
    FOR(phase,1,300){
        double L1=L+(R-L)/3,R1=R-(R-L)/3;
        if (cal(L1)>cal(R1)) L=L1;
        else R=R1;
    }
    printf("%.9f",cal(L));
}