#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int H[2003];
pair<int,int> P[2003];


void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N;
    FOR(i,N) cin>>H[i],P[i]=make_pair(H[i],i+1);
    sort(P,P+N);
    
    x=y=-1;
    FOR(i,N-1) {
        if(P[i].first==P[i+1].first) {
            if(x==-1) x=i;
            else y=i;
        }
    }
    
    if(y==-1) return _P("NO\n");
    _P("YES\n");
    FOR(j,N) _P("%d ",P[j].second);
    _P("\n");
    swap(P[x],P[x+1]);
    FOR(j,N) _P("%d ",P[j].second);
    _P("\n");
    swap(P[y],P[y+1]);
    FOR(j,N) _P("%d ",P[j].second);
    _P("\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}