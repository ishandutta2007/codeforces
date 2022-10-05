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

int N,X;
int T[2001],H[2001],M[2001];
int NN[2];
int vis[2001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>X;
    FOR(i,N) {
        cin>>T[i]>>H[i]>>M[i];
    }
    int ma=0;
    FOR(i,2) {
        x=0,j=i,y=X;
        ZERO(vis);
        while(1) {
            k=-1;
            FOR(f,N) if(vis[f]==0 && T[f]==j && H[f]<=y) {
                if(k==-1 || M[f]>M[k]) k=f;
            }
            if(k==-1) break;
            vis[k]=1;
            y+=M[k];
            j^=1;
            x++;
        }
        ma=max(ma,x);
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