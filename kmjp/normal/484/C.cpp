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

string S;
int L,M;
int LS[1<<20];
int P[2][1<<20],Q[1<<20],R[1<<20];

void makeQ(int v) {
    int i,j,k;
    FOR(i,L) Q[i]=i;
    FOR(j,20) {
        int cur=j%2,tar=cur^1;
        if(v&(1<<j)) {
            FOR(i,L) R[i]=Q[P[cur][i]];
            FOR(i,L) Q[i]=R[i];
            v ^= (1<<j);
            if(v==0) return;
        }
        
        // P=P*P
        FOR(i,L) P[tar][i]=P[cur][P[cur][i]];
    }
}

void solve() {
    int i,j,k,d,l,r,x,y; string s;
    
    cin>>S;
    L=S.size();
    
    FOR(i,L) LS[i]=(i+(L-1))%L;
    
    cin>>M;
    while(M--) {
        cin>>k>>d;
        
            x=0;
            FOR(i,d) for(j=i;j<k;j+=d) P[0][j]=((x++)+(L-1))%L;
            for(i=k;i<L;i++) P[0][i]=(i+(L-1))%L;
            
            makeQ(L-k+1);
            
            s=S;
            FOR(i,L) s[Q[i]]=S[i];
            FOR(i,L) S[i]=s[(i+(k-1))%L];
        _P("%s\n",S.c_str());
        //cout<<S<<endl;
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}