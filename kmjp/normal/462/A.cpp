#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
string S[101];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(y,N) cin>>S[y];
    int ng=0;
    FOR(y,N) FOR(x,N) {
        i=(y>0&&S[y-1][x]=='o')+(y<N-1&&S[y+1][x]=='o')+(x<N-1&&S[y][x+1]=='o')+(x>0&&S[y][x-1]=='o');
        ng|=i%2;
    }
    if(ng) _P("NO\n");
    else _P("YES\n");
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}