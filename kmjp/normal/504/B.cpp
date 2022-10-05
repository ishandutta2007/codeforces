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

template<class V, int ME> class BIT {
public:
    V bit[1<<ME];
    int lower_bound(V val) {
        V tv=0; int i,ent=0;
        for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
        return ent;
    }
    V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
    void update(int e, V val) {e++; while(e<=1<<ME) bit[e-1]+=val,e+=e&-e;}
};
BIT<int,20> btp,btq,btr;

int N;
int P[201000],Q[201000];
int P2[201000],Q2[201000],R[201000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) btp.update(i+1,1),btq.update(i+1,1),btr.update(i+1,1);
    
    FOR(i,N) {
        cin>>P[i];
        P2[i]=btp.total(P[i]);
        btp.update(P[i]+1,-1);
    }
    FOR(i,N) {
        cin>>Q[i];
        Q2[i]=btq.total(Q[i]);
        btq.update(Q[i]+1,-1);
    }
    
    for(i=N-1;i>=0;i--) {
        R[i]+=P2[i]+Q2[i];
        while(R[i]>=(N-i)) {
            R[i]-=(N-i);
            if(i!=0) R[i-1]++;
        }
        
    }
    
    FOR(i,N) {
        
        y=(1<<19)-1;
        for(j=18;j>=0;j--) if(btr.total(y-(1<<j))>=R[i]) y-=1<<j;
        
        _P("%d ",y);
        btr.update(y,-1);
    }
    _P("\n");
        
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}