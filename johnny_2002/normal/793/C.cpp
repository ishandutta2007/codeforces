#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> range;

#define X first
#define Y second

const int N=90;
const int MOD=1e9+7;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
const int inf=1e6+10;
const int eps=1e-8;


range check(int st,int sp,int L,int R){
    if (sp==0){
        if (st>=R||st<=L) return range(1,0);
        return range(0,1e6);
    }
    if (sp<0) return check(-st,-sp,-R,-L);
    if (st>=R) return range(1,0);
    if (st<=L) return range((L-st+.0)/sp,(R-st+.0)/sp);
    return range(0,(R-st+.0)/sp);
}
void joint(range &a,range b){
    a.X=max(a.X,b.X);
    a.Y=min(a.Y,b.Y);
}
void prepare(){
    int n,xta,yta,xtb,ytb;
    cin>>n>>xta>>yta>>xtb>>ytb;
    range ans=range(0,1e6);
    if (xta==xtb||yta==ytb){
        printf("-1");
        return;
    }
    while (n--){
        int xc,yc,sx,sy;
        cin>>xc>>yc>>sx>>sy;
        joint(ans,check(xc,sx,xta,xtb));
        joint(ans,check(yc,sy,yta,ytb));
    }
    if (ans.X+eps>=ans.Y) printf("-1");
    else printf("%.9f",ans.X+eps);
}
int main(){
    prepare();
//    cout<<solve();
}