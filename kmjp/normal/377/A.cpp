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

int H,W,K;
string S[501];
vector<pair<int,int> > PP;
int vis[501][501];


int dfs(int x,int y,int prex,int prey) {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int i;
    vis[y][x]=1;
    FOR(i,4) {
        int tarx=x+dx[i];
        int tary=y+dy[i];
        if(tarx<0 || tarx>=W || tary<0 || tary>=H) continue;
        if(tarx==prex && tary==prey) continue;
        if(vis[tary][tarx]) continue;
        if(S[tary][tarx]=='#') continue;
        dfs(tarx,tary,x,y);
    }
    PP.push_back(make_pair(x,y));
}

void solve() {
    int f,i,j,k,l,x,y;
    int sx,sy;
    
    cin>>H>>W>>K;
    FOR(y,H) {
        cin>>S[y];
        FOR(x,W) if(S[y][x]=='.') sx=x,sy=y;
    }
    
    dfs(sx,sy,-1,-1);
    FOR(i,K) {
        S[PP[i].second][PP[i].first]='X';
    }
    FOR(y,H) cout << S[y] << endl;
    
    
}


int main(int argc,char** argv){
    string s;
    ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}