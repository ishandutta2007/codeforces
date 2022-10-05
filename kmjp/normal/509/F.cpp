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

int N,B[600];
ll mo=1000000007;
ll pat;
ll sp[502][502];
ll sub[502][502];

void solve() {
    int i,j,k,l,r,x,y,w; string s;
    
    cin>>N;
    pat=1;
    FOR(i,N) cin>>B[i], sp[i][i]=sub[i][i]=1;
    
    for(w=1;w<N;w++) {
        for(l=0;(r=l+w)<N;l++) {
            sp[l][r]=sub[l][r]=sp[l+1][r];
            for(x=l+1;x<=r;x++) if(B[l]<B[x])  sp[l][r]+=sub[l][x-1]*sp[x][r]%mo;
            sp[l][r] %= mo;
        }
    }
    
    cout<<sub[0][N-1]<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}