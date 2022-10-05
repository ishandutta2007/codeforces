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

int N,K,X;
int C[101];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>K>>X;
    FOR(i,N) cin>>C[i];
    int ma=0;
    FOR(i,N-1) {
        vector<int> V;
        FOR(j,i) V.push_back(C[j]);
        V.push_back(X);
        for(j=i;j<N;j++) V.push_back(C[j]);
        while(1) {
            vector<int> V2;
            x=0,y=0;
            FOR(j,V.size()) {
                if(x!=V[j]) x=V[j],y=0;
                if(x==V[j]) y++;
                if(y>=3) {
                    while(!V2.empty() && V2[V2.size()-1]==x) V2.resize(V2.size()-1);
                }
                else V2.push_back(x);
            }
            if(V==V2) break;
            V=V2;
        }
        ma=max(ma,N-(int)V.size());
    }
    cout << ma << endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}