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

int N,M,K;
int A[101000],B[101000];

int but[101000];
int pos[101000];
ll ret=0;

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N>>M>>K;
    
    FOR(i,N) {
        cin>>A[i];
        but[i]=--A[i];
        pos[A[i]]=i;
    }
    FOR(i,M) {
        cin>>x;
        x--;
        ret += pos[x]/K+1;
        if(pos[x]>0) {
            y=but[pos[x]-1];
            swap(but[pos[x]],but[pos[x]-1]);
            pos[y]++;
            pos[x]--;
        }
    }
    cout<<ret<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}