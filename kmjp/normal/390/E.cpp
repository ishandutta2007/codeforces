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

template<class V, int ME> class BIT_r {
public:
    V bit[2][1<<ME];
    BIT_r(){clear();};
    void clear() {ZERO(bit);};
    
    void update(int entry, V val0, V val1) {
        entry++;
        while(entry <= 1<<ME) bit[0][entry-1]+=val0, bit[1][entry-1] += val1, entry += entry & -entry;
    }
    V total(int entry) {
        int e=entry++;
        V v0=0,v1=0;
        while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
        return e*v0+v1;
    }
    void add(int L, int R, V val) { // add val to L<=x<=R
        update(L,val,-val*(L-1));
        update(R+1,-val,val*R);
    }
};

BIT_r<ll,23> btx,bty;

int R,C,W;
ll tot;

void solve() {
    int f,i,j,k,l,x,y;
    ll x1,x2,y1,y2,v;
    
    cin>>R>>C>>W;
    
    FOR(i,W) {
        cin>>j;
        if(j==0) {
            cin>>x1>>y1>>x2>>y2>>v;
            tot += (x2-x1+1)*(y2-y1+1)*v;
            btx.add(x1,x2,v*(y2-y1+1));
            bty.add(y1,y2,v*(x2-x1+1));
        }
        else {
            cin>>x1>>y1>>x2>>y2;
            ll r1 = bty.total(y2)-bty.total(y1-1);
            ll r2 = btx.total(x2)-btx.total(x1-1);
            _P("%lld\n",r1+r2-tot);
        }
    }
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}