#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
int C[30];
vector<int> V;


void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    x=0;
    FOR(i,N) {
        cin>>C[i];
        if(C[i]==2) return _P("NO\n");
        V.push_back(C[i]);
    }
    
    sort(V.begin(),V.end());
    int mask=1<<(N-1);
    if(V[N-1]!=N) return _P("NO\n");
    for(i=N-1;i>=0;i--) {
        if((mask & (1<<i))==0) return _P("NO\n");
        if(V[i]==1) continue;
        int x=V[i]-1,y=0;
        for(j=i-1;j>=0;j--) {
            if(x>=V[j] && (mask & (1<<j))==0)  {
                x-=V[j];
                y++;
                mask |= 1<<j;
            }
        }
        if(x!=0 || y<2) return _P("NO\n");
    }
    return _P("YES\n");
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}