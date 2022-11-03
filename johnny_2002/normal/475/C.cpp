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
const int N=1e3+10;

char s[N][N];
int n,m,a[N][N]={0},top;
ii t[N<<2];
void prepare(){
    scanf("%d%d",&n,&m);
    REP(i,0,n) scanf("\n%s",&s[i]);
    FOR(i,1,n)
        FOR(j,1,m) a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(s[i-1][j-1]=='X');
}
bool comp(ii a,ii b){
    return a.X*a.Y<b.X*b.Y;
}
int cal(int x1,int y1,int x2,int y2){
    return a[x2][y2]+a[x1-1][y1-1]-a[x1-1][y2]-a[x2][y1-1];
}
void solve(){
    ii st=ii(1,1);
    while (s[st.X-1][st.Y-1]=='.'){
        st.Y++;
        if (st.Y>m) st.X++,st.Y=1;
    }
    ii e=ii(n,m);
    while (s[e.X-1][e.Y-1]=='.'){
        e.Y--;
        if (e.Y==0) e.X--,e.Y=m;
    }
    int x=st.X,y=st.Y,k1=1,k2=1;
    while (s[x+k1-1][y-1]=='X') k1++;
    while (s[x-1][y+k2-1]=='X') k2++;
    int top=0;
    FOR(i,1,k1-1) t[++top]=ii(i,k2);
    FOR(i,1,k2) t[++top]=ii(k1,i);
    sort(t+1,t+top+1,comp);
    //printf("%d %d\n",st.X,st.Y);
    //FOR(i,1,top) printf("%d %d\n",t[i].X,t[i].Y);
    FOR(i,1,top){
        int w=t[i].Y,h=t[i].X;
        int x=st.X+h-1,y=st.Y+w-1,re=w*h;
        bool check=true;
        //if (x!=2||y!=2) continue;
        while (check){
            //printf("%d %d\n",x,y);
            int next=0;
            if (x==e.X&&y==e.Y) break;
            if (cal(x-h+1,y-w+2,x,y+1)==w*h) next=1;
            if (cal(x-h+2,y-w+1,x+1,y)==w*h){
                if (next==1) check=false;
                else next=-1;
            }
            if (next==0) check=false;
            if (next==1){
                y++;
                FOR(i,x-h+1,x) re+=(s[i-1][y-1]=='X');
            }
            if (next==-1){
                x++;
                FOR(i,y-w+1,y) re+=(s[x-1][i-1]=='X');
            }
        }
        //printf("%d %d %d\n",w,h,re);
        if (check&&re==cal(1,1,n,m)) {printf("%d",w*h);return;}
    }
    printf("-1");
}
int main(){
    prepare();
    solve();
}