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

int N,W;
ll A[300000],B[300000];

int KMPT[4*100000];
ll res;

int KMP(vector<int>& tar,vector<int>& pat, int cur=0) {
    int c,p=0,l,pl;
    FOR(c,tar.size()) {
        while(cur>-1 && pat[cur]!=tar[c]) cur=KMPT[cur];
        if(++cur >= pat.size()) res++, cur=KMPT[cur];
    }
    return cur;
}

void prepKMP(vector<int>& str) {
    int i,n;
    
    n=KMPT[0]=-1;
    FOR(i,str.size()) {
        while(n>-1 && str[i]!=str[n]) n=KMPT[n];
        KMPT[i+1]=++n;
    }
}


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>W;
    FOR(i,N) cin>>A[i];
    FOR(i,W) cin>>B[i];
    
    if(W==1) return _P("%d\n",N);
    vector<int> D,E;
    FOR(i,N-1) D.push_back(A[i+1]-A[i]);
    FOR(i,W-1) E.push_back(B[i+1]-B[i]);
    prepKMP(E);
    KMP(D,E);
    cout << res << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}