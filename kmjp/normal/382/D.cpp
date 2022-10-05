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

int H,W;
string S[2001];
pair<int,int> P[2001][2001];
int D[2001][2001];

void solve() {
    int f,i,j,k,l,x,y,ma=0;
    
    MINUS(P);
    MINUS(D);
    
    queue<pair<int,int> > Q;
    cin>>H>>W;
    FOR(y,H) {
        cin>>S[y];
        FOR(x,W) if(S[y][x]=='#') D[y][x]=0,P[y][x]=make_pair(x,y),Q.push(make_pair(x,y));
    }
    
    while(!Q.empty()) {
        int cx=Q.front().first;
        int cy=Q.front().second;
        Q.pop();
        
        FOR(i,4) {
            int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
            int ty=cy+dy[i],tx=cx+dx[i];
            if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
            if(D[ty][tx]!=-1) continue;
            if(i==0 && S[ty][tx]!='<') continue;
            if(i==1 && S[ty][tx]!='>') continue;
            if(i==2 && S[ty][tx]!='^') continue;
            if(i==3 && S[ty][tx]!='v') continue;
            D[ty][tx]=D[cy][cx]+1;
            if(D[ty][tx]==1) P[ty][tx]=make_pair(tx,ty);
            else P[ty][tx]=P[cy][cx];
            Q.push(make_pair(tx,ty));
            ma=max(ma,D[ty][tx]);
        }
    }
    
    FOR(y,H) FOR(x,W) if(D[y][x]==-1) return _P("-1\n");
    if(ma==0) return _P("0\n");
    set<pair<int,int> > S;
    FOR(y,H) FOR(x,W) if(D[y][x]==ma) S.insert(P[y][x]);
    
    _P("%d\n",2*ma-(S.size()==1));
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}