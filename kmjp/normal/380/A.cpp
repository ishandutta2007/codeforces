#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

ll M,L,N;
int MM[200000];
map<ll,int> H;
map<ll,ll> R;

void solve() {
    int f,i,j,k,x,y;
    ll l;
    
    cin>>M;
    
    vector<ll> V;
    L=0;
    l=0;
    
    FOR(i,M) {
        cin>>x;
        if(x==1) {
            cin>>y;
            H[l]=y;
            V.push_back(l);
            R[l]=1;
            if(l<200000) MM[l]=y;
            l++;
        }
        else {
            cin>>x>>y;
            while(y) {
                if(l+x<200000) {
                    FOR(f,x) {
                        H[l]=MM[f];
                        MM[l]=MM[f];
                        R[l]=1;
                        V.push_back(l);
                        l++;
                    }
                    y--;
                }
                else {
                    V.push_back(l);
                    R[l]=x;
                    l+=x*(ll)y;
                    y=0;
                }
            }
        }
    }
    
    ll xx;
    cin>>N;
    FOR(i,N) {
        cin>>xx;
        xx--;
        if(H.find(xx)==H.end()) {
            ret:
            int y=lower_bound(V.begin(),V.end(),xx)-V.begin()-1;
            xx=(xx-V[y])%R[V[y]];
            if(xx>=200000) goto ret;
            _P("%d ",MM[xx]);
        }
        else {
            _P("%d ",H[xx]);
        }
    }
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}