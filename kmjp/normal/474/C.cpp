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
int X[4],Y[4],A[4],B[4];

pair<int,int> rot(int x,int y,int a,int b,int num) {
    while(num--) {
        int ox=x,oy=y;
        x=a+(b-oy);
        y=b-(a-ox);
    }
    return make_pair(x,y);
}

bool sq(pair<int,int> P1,pair<int,int> P2,pair<int,int> P3,pair<int,int> P4) {
    pair<int,int> p;
    if(P1==P2) return false;
    p.first=P2.first+(P1.second-P2.second);
    p.second=P2.second-(P1.first-P2.first);
    if(p!=P3) return false;
    p.first=P1.first+(P1.second-P2.second);
    p.second=P1.second-(P1.first-P2.first);
    return p==P4;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        FOR(j,4) cin>>X[j]>>Y[j]>>A[j]>>B[j];
        int ma=100;
        FOR(j,256) {
            pair<int,int> P[4];
            FOR(k,4) P[k]=rot(X[k],Y[k],A[k],B[k],(j>>(2*k))%4);
            x=j%4+j/4%4+j/16%4+j/64%4;
            if(sq(P[0],P[1],P[2],P[3])) ma=min(ma,x);
            if(sq(P[0],P[1],P[3],P[2])) ma=min(ma,x);
            if(sq(P[0],P[2],P[1],P[3])) ma=min(ma,x);
            if(sq(P[0],P[2],P[3],P[1])) ma=min(ma,x);
            if(sq(P[0],P[3],P[1],P[2])) ma=min(ma,x);
            if(sq(P[0],P[3],P[2],P[1])) ma=min(ma,x);
        }
        if(ma==100) ma=-1;
        cout << ma << endl;
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}