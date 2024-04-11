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
int A[401][401];
int ma;

short may[160001][401];
vector<pair<short,short> > L[401][401],R[401][401];
int lef[405];

void solve() {
    int i,j,k,l,r,x,y,y1,y2,x2; string s;
    cin>>H>>W;
    MINUS(may);
    FOR(y,H) FOR(x,W) {
        cin>>A[y][x];
        A[y][x]--;
        for(x2=x;x2>=0;x2--) if(may[A[y][x]][x2]>=0) {
            if(L[y][x].empty() || L[y][x].back().second<may[A[y][x]][x2]) L[y][x].push_back(make_pair(x2,may[A[y][x]][x2]));
        }
        for(x2=x+1;x2<W;x2++) if(may[A[y][x]][x2]>=0) {
            if(R[y][x].empty() || R[y][x].back().second<may[A[y][x]][x2]) R[y][x].push_back(make_pair(x2,may[A[y][x]][x2]));
        }
        may[A[y][x]][x]=y;
        reverse(L[y][x].begin(),L[y][x].end());
        reverse(R[y][x].begin(),R[y][x].end());
    }
    
    FOR(y,H) {
        MINUS(lef);
        for(y2=y;y2<H;y2++) {
            FOR(x,W) {
                if(L[y2][x].size() && L[y2][x].back().second<y) L[y2][x].pop_back();
                if(R[y2][x].size() && R[y2][x].back().second<y) R[y2][x].pop_back();
                
                if(R[y2][x].size()) lef[R[y2][x].back().first]=max(lef[R[y2][x].back().first],x);
                if(L[y2][x].size()) lef[x]=max(lef[x],(int)L[y2][x].back().first);
                
                if(x) lef[x]=max(lef[x],lef[x-1]);
                ma=max(ma,(y2-y+1)*(x-lef[x]));
            }
        }
    }
    
    cout<<ma<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}