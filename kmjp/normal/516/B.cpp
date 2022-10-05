#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[2020];
int emp[2020][2020];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>H>>W;
    FOR(y,H) cin>>S[y];
    queue<int> Q;
    FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
        emp[y][x] += (y>0&&S[y-1][x]=='.');
        emp[y][x] += (y<H-1&&S[y+1][x]=='.');
        emp[y][x] += (x>0&&S[y][x-1]=='.');
        emp[y][x] += (x<W-1&&S[y][x+1]=='.');
        if(emp[y][x]==1) Q.push(y*10000+x);
    }
    
    while(Q.size()) {
        int k=Q.front();
        Q.pop();
        y=k/10000,x=k%10000;
        if(S[y][x]!='.') continue;
        
        int my=-1,mx=-1;
        if(y>0 && S[y-1][x]=='.') {
            S[y-1][x]='^';
            S[y][x]='v';
            my=y-1;
            mx=x;
        }
        if(y<H-1 && S[y+1][x]=='.') {
            S[y+1][x]='v';
            S[y][x]='^';
            my=y+1;
            mx=x;
        }
        if(x>0 && S[y][x-1]=='.') {
            S[y][x-1]='<';
            S[y][x]='>';
            my=y;
            mx=x-1;
        }
        if(x<W-1 && S[y][x+1]=='.') {
            S[y][x+1]='>';
            S[y][x]='<';
            my=y;
            mx=x+1;
        }
        if(my>-1) {
            FOR(i,4) {
                int dd[4]={1,0,-1,0};
                int ty=y+dd[i],tx=x+dd[i^1];
                if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
                if(S[ty][tx]!='.') continue;
                emp[ty][tx]--;
                if(emp[ty][tx]==1) Q.push(ty*10000+tx);
            }
            FOR(i,4) {
                int dd[4]={1,0,-1,0};
                int ty=my+dd[i],tx=mx+dd[i^1];
                if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
                if(S[ty][tx]!='.') continue;
                emp[ty][tx]--;
                if(emp[ty][tx]==1) Q.push(ty*10000+tx);
            }
        }
    }
    
    FOR(y,H) FOR(x,W) if(S[y][x]=='.') return _P("Not unique\n");
    FOR(y,H) cout<<S[y]<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}