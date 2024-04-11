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

int H,W,O;
string S[50];
int SX,SY;
int ox[8],oy[8],oc[8];
int rm[20][20];
int cost[20][20][1<<10];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>H>>W;
    
    FOR(y,H) {
        cin>>S[y];
        FOR(x,W) if(S[y][x]=='S') SX=x,SY=y,S[y][x]='.';
        FOR(x,W) if(S[y][x]>='1' && S[y][x]<='8') ox[S[y][x]-'1']=x,oy[S[y][x]-'1']=y,O=max(O,S[y][x]-'0');
    }
    FOR(x,O) cin>>oc[x];
    FOR(y,H) FOR(x,W) if(S[y][x]=='B') ox[O]=x,oy[O]=y,oc[O]=-1<<20,O++;
    
    FOR(i,O) for(x=ox[i]+1;x<W;x++) rm[oy[i]][x] |= 1<< i;
    
    FILL_INT(cost,100000000);
    cost[SY][SX][0]=0;
    multimap<int,int> Q;
    Q.insert(make_pair(0,SY*20000+SX*1000));
    while(!Q.empty()) {
        int co = Q.begin()->first;
        int key=Q.begin()->second;
        Q.erase(Q.begin());
        int cx=(key/1000)%20,cy=(key/20000)%20,cm=key%1000;
        if(co != cost[cy][cx][cm]) continue;
        
        FOR(i,4) {
            int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
            int ty=cy+dy[i],tx=cx+dx[i],tm=cm;
            if(ty<0 || tx<0 || ty>=H || tx>=W) continue;
            if(S[ty][tx]!='.') continue;
            if(i==0) tm^=rm[cy][cx];
            if(i==1) tm^=rm[cy-1][cx];
            if(cost[ty][tx][tm] > co + 1) {
                cost[ty][tx][tm] = co + 1;
                Q.insert(make_pair(cost[ty][tx][tm], ty*20000+tx*1000+tm));
            }
        }
    }
    
    int ma=0;
    FOR(i,1<<O) {
        int co=-cost[SY][SX][i];
        FOR(x,O) if(i&(1<<x)) co += oc[x];
        ma=max(ma,co);
    }
    _P("%d\n",ma);
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}