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

int N;
int V[3][101000];
map<int,int> M;
int mi[3][303000];
set<pair<int,int> > P;
multiset<int> R;

void add(int bx,int cy) {
    int y;
    set<pair<int,int> >::iterator it=P.lower_bound(make_pair(bx,cy));
    if(it->second>=cy) return;
    y=it->second;
    R.insert(bx+y);
    it--;
    while(it->second<=cy) R.erase(R.lower_bound(it->first+y)),y=it->second, P.erase(it--);
    assert(R.count(it->first+y)>0);
    R.erase(R.lower_bound(it->first+y));
    
    P.insert(make_pair(bx,cy));
    R.insert(it->first+cy);
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N;
    int debug=0;
    FOR(i,3) {
        FOR(j,3*N+5) mi[i][j]=4*N;
        FOR(j,N) {
            cin>>x;
            if(M.count(x)==0) M[x]=M.size()-1;
            mi[i][M[x]]=min(mi[i][M[x]], j+1);
        }
    }
    
    int ans=mi[0][M.size()-1];
    P.insert(make_pair(0,9*N+1));
    P.insert(make_pair(9*N+1,0));
    R.insert(0);
    for(i=M.size()-1;i>=0;i--) {
        ans=min(ans,mi[0][i]+*R.begin());
        add(mi[1][i],mi[2][i]);
        /*
        _P("%d %d %d (%d %d)::",i,mi[0][i],*R.begin(),mi[1][i],mi[2][i]);
        ITR(it,P) _P("(%d,%d) ",it->first,it->second);
        ITR(it,R) _P("%d,",*it);
        _P("\n");
        */
    }
    ans=min(ans,*R.begin());
    cout<<ans<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}