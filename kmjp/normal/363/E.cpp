#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int W,H,R;
int mat[1024][1024];
int CA[1024][1024];
int LM[1024][1024],LC[1024][1024];
int RM[1024][1024],RC[1024][1024];
int LIM[1024],LIC[1024];


int RR[1024];
int RR2[1024];

map<int, vector<int> > S;

int circle(int cy,int cx) {
    int a=0,x,y;
    for(x=cx-R;x<=cx+R;x++) for(y=cy-RR[abs(x-cx)];y<=cy+RR[abs(x-cx)];y++) a+=mat[y][x];
    return a;
}

void solve() {
    int f,i,j,k,l,x,y,x2,y2;
    ll r;
    
    cin>>H>>W>>R;
    if(2*R+1>H || 2*R+1>W) return _P("0 0\n");
    FOR(y,H) FOR(x,W) cin>>mat[y][x];
    
    MINUS(RR);
    MINUS(RR2);
    FOR(i,R+1) while(i*i+(RR[i]+1)*(RR[i]+1)<=R*R) RR[i]++;
    FOR(x,R+1) FOR(x2,R+1) RR2[x+x2]=max(RR2[x+x2],RR[x]+RR[x2]);
    //FOR(i,2*R+2) _P("%d ",RR2[i]);
    //_P("\n");
    
    CA[R][R]=circle(R,R);
    for(y=R;y<H-R;y++) {
        if(y==R) CA[R][R]=circle(R,R);
        else {
            CA[y][R]=CA[y-1][R];
            for(x=0;x<2*R+1;x++) CA[y][R]+=mat[y+RR[abs(x-R)]][x];
            for(x=0;x<2*R+1;x++) CA[y][R]-=mat[y-1-RR[abs(x-R)]][x];
        }
        
        for(x=R+1;x<W-R;x++) {
            CA[y][x]=CA[y][x-1];
            for(y2=y-R;y2<=y+R;y2++) CA[y][x]+=mat[y2][x+RR[abs(y2-y)]];
            for(y2=y-R;y2<=y+R;y2++) CA[y][x]-=mat[y2][x-1-RR[abs(y2-y)]];
        }
    }
    
    /* merge cells to line */
    for(y=R;y<H-R;y++) {
        LM[y][R]=CA[y][R];
        LC[y][R]=1;
        for(x=R+1;x<W-R;x++) {
            LM[y][x]=LM[y][x-1];
            LC[y][x]=LC[y][x-1];
            if(CA[y][x]==LM[y][x]) LC[y][x]++;
            else if(CA[y][x]>LM[y][x]) {
                LM[y][x]=CA[y][x];
                LC[y][x]=1;
            }
        }
        RM[y][W-R-1]=CA[y][W-R-1];
        RC[y][W-R-1]=1;
        for(x=W-R-2;x>=R;x--) {
            RM[y][x]=RM[y][x+1];
            RC[y][x]=RC[y][x+1];
            if(CA[y][x]==RM[y][x]) RC[y][x]++;
            else if(CA[y][x]>RM[y][x]) {
                RM[y][x]=CA[y][x];
                RC[y][x]=1;
            }
        }
    }
    
    /* merge lines */
    LIM[H-R-1]=RM[H-R-1][R];
    LIC[H-R-1]=RC[H-R-1][R];
    for(y=H-R-2;y>=R;y--) {
        LIM[y]=LIM[y+1];
        LIC[y]=LIC[y+1];
        if(LIM[y]==RM[y][R]) LIC[y]+=RC[y][R];
        if(LIM[y]<RM[y][R]) LIM[y]=RM[y][R],LIC[y]=RC[y][R];
    }
    
    ll ma=0,mc=0;
    for(y=R;y<H-R;y++) {
        for(x=R;x<W-R;x++) {
            int s1=CA[y][x],s2,ss;
            
            if(x+2*R+1<W-R) {
                s2=RM[y][x+2*R+1];
                ss=s1+s2;
                if(ss==ma) mc+=RC[y][x+2*R+1];
                if(ss>ma) ma=ss,mc=RC[y][x+2*R+1];
            }
            for(y2=y+1;y2<H-R && y2<=y+2*R;y2++) {
                if(x-(RR2[y2-y]+1)>=R) {
                    s2=LM[y2][x-(RR2[y2-y]+1)];
                    ss=s1+s2;
                    if(ss==ma) mc+=LC[y2][x-(RR2[y2-y]+1)];
                    if(ss>ma) ma=ss,mc=LC[y2][x-(RR2[y2-y]+1)];
                }
                if(x+(RR2[y2-y]+1)<W-R) {
                    s2=RM[y2][x+(RR2[y2-y]+1)];
                    ss=s1+s2;
                    if(ss==ma) mc+=RC[y2][x+(RR2[y2-y]+1)];
                    if(ss>ma) ma=ss,mc=RC[y2][x+(RR2[y2-y]+1)];
                }
            }
            
            y2=y+2*R+1;
            if(y2<=H-R-1) {
                s2=LIM[y2];
                ss=s1+s2;
                if(ss==ma) mc+=LIC[y2];
                if(ss>ma) ma=ss,mc=LIC[y2];
            }
        }
    }
    cout << ma << " " << mc << endl;
    /*
    for(y=R;y<H-R;y++) {
        for(x=R;x<W-R;x++) _P("%d ",CA[y][x]);
        _P("\n");
    }
    
    for(y=R;y<H-R;y++) {
        for(x=R;x<W-R;x++) _P("(%d:%d-%d:%d) ",LM[y][x],LC[y][x],RM[y][x],RC[y][x]);
        _P("\n");
    }
    */
    
    
    
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}