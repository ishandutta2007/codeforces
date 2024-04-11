#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int H,W;
string S[2020];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    queue<int> Q;
    cin>>H>>W;
    FOR(y,H) {
        cin>>S[y];
        FOR(x,W) if(S[y][x]=='.') Q.push(y*2000+x);
    }
    
    while(Q.size()) {
        int k=Q.front();
        int ty=k/2000,tx=k%2000;
        Q.pop();
        FOR(i,9) {
            int cy=ty-1+i/3;
            int cx=tx-1+i%3;
            if(cy<0 || cy>=H || cx<0 || cx>=W) continue;
            if(S[cy][cx]=='*') continue;
            
            if(cy>0 && cx>0 && S[cy-1][cx-1]=='*' && S[cy-1][cx]=='.' && S[cy][cx-1]=='.') {
                S[cy-1][cx-1]='.';
                Q.push((cy-1)*2000+(cx-1));
            }
            if(cy<H-1 && cx>0 && S[cy+1][cx-1]=='*' && S[cy+1][cx]=='.' && S[cy][cx-1]=='.') {
                S[cy+1][cx-1]='.';
                Q.push((cy+1)*2000+(cx-1));
            }
            if(cy>0 && cx<W-1 && S[cy-1][cx+1]=='*' && S[cy-1][cx]=='.' && S[cy][cx+1]=='.') {
                S[cy-1][cx+1]='.';
                Q.push((cy-1)*2000+(cx+1));
            }
            if(cy<H-1 && cx<W-1 && S[cy+1][cx+1]=='*' && S[cy+1][cx]=='.' && S[cy][cx+1]=='.') {
                S[cy+1][cx+1]='.';
                Q.push((cy+1)*2000+(cx+1));
            }
        }
    }
    
    FOR(y,H) cout<<S[y]<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}