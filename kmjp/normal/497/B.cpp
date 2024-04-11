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

int N, A[102000];
vector<int> W[2];
vector<pair<int,int> > R;

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N;
    FOR(i,N) cin>>A[i];
    FOR(i,N) {
        if(A[N-1]==1 && A[i]==2) A[i]=0;
        else if(A[N-1]==2) A[i]--;
    }
    FOR(i,N) W[A[i]].push_back(i);
    
    for(i=1;i<=W[1].size();i++) {
        int w0=0,w1=0,ng=0;
        x=y=-1;
        while(1) {
            if(x+i>=W[0].size() && y+i>=W[1].size()) {
                ng=1;
                break;
            }
            if(x+i>=W[0].size() || (y+i<W[1].size() && W[1][y+i]<W[0][x+i])) {
                y+=i;
                w1++;
                if(x+i<W[0].size()) x=lower_bound(W[0].begin(),W[0].end(),W[1][y])-W[0].begin()-1;
            }
            else {
                x+=i;
                w0++;
                if(y+i<W[1].size()) y=lower_bound(W[1].begin(),W[1].end(),W[0][x])-W[1].begin()-1;
            }
            if(y==W[1].size()-1) break;
        }
        if(ng==0 && w1>w0) R.push_back(make_pair(w1,i));
    }
    
    sort(ALL(R));
    _P("%d\n",R.size());
    FOR(i,R.size()) _P("%d %d\n",R[i].first,R[i].second);
    
}
 

int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}