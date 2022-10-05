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

int N;
ll A[300000];

void solve() {
    int f,i,j,k,l;
    ll x,y;
    int tot=0;
    cin>>N;
    FOR(i,N) cin>>A[i];
    
    int pre=0;
    x=0,y=-1;
    while(x<N) {
        if(A[x]!=-1) {
            if(y==-1) {
                y=x;
                x++;
            }
            else {
                tot++;
                if(abs(A[x]-A[y])%(x-y)==0) {
                    ll diff=(A[x]-A[y])/(x-y);
                    int ng=0;
                    for(i=pre;i<y;i++) {
                        ll val=A[y]+diff*(i-y);
                        if(val<=0) ng++;
                    }
                    
                    if(!ng) {
                        x++;
                        while(x<N) {
                            y=A[x-1]+diff;
                            if(y<=0) break;
                            if(A[x]>0 && A[x]!=y) break;
                            A[x]=y;
                            x++;
                        }
                    }
                }
                y=-1;
                pre=x;
            }
        }
        else {
            x++;
        }
        
    }
    if(pre<N) tot++;
    _P("%d\n",tot);
    
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}