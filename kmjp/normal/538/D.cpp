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

int N;
string S[51];
string R[101];
vector<pair<int,int> > C;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(y,N) {
        cin>>S[y];
        FOR(x,N) if(S[y][x]=='o') C.emplace_back(x,y);
    }
    if(C.empty()) return _P("NO\n");
    
    FOR(y,2*N-1) s+=".";
    FOR(y,2*N-1) R[y]=s;
    R[N-1][N-1]='o';
    
    FOR(y,N) FOR(x,N) if(S[y][x]=='x') {
        int ok2=0;
        FORR(r,C) {
            int dx=x-r.first;
            int dy=y-r.second;
            int ok=1;
            FORR(r2,C) {
                int tx=r2.first+dx;
                int ty=r2.second+dy;
                if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
                if(S[ty][tx]=='.') {
                    ok=0;
                    break;
                }
            }
            if(ok==1) {
                ok2=1;
                R[N+dy-1][N+dx-1]='x';
                break;
            }
        }
        if(ok2==0) return _P("NO\n"); 
        
    }
    
    cout<<"YES"<<endl;
    FOR(y,2*N-1) cout<<R[y]<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}