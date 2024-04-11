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

template<class V,int NV> class SegTree_1 {
public:
    vector<V> val;
    vector<int> val2;
    V comp(V l,V r){ return max(l,r);};
    
    SegTree_1(){val.resize(NV*2); val2.resize(NV*2);clear();};
    void clear() { int i; FOR(i,NV*2) val[i]=val2[i]=0;}
    
    V getval(int x,int y,int l,int r,int k) {
        if(r<=x || y<=l) return 0;
        if(x<=l && r<=y) return val[k];
        return getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
    }
    V getval(int x,int y) { return getval(x,y,0,NV,1);}
    
    void update2(int x,int y,int l,int r,int k,int v) {
        if(r<=x || y<=l) return;
        if(val2[k]<v) return;
        if(l+1==r) {
            val[k]%=v;
            val2[k]=val[k];
            return;
        }
        update2(x,y,l,(l+r)/2,k*2,v);
        update2(x,y,(l+r)/2,r,k*2+1,v);
        val[k]=val[k*2]+val[k*2+1];
        val2[k]=max(val2[k*2],val2[k*2+1]);
    }
    void update2(int x,int y,int v) { update2(x,y,0,NV,1,v);}
    void update(int entry, V v) {
        entry += NV;
        val[entry]=val2[entry]=v;
        while(entry>1) entry>>=1, val[entry]=val[entry*2]+val[entry*2+1], val2[entry]=max(val2[entry*2],val2[entry*2+1]);
    }
};


SegTree_1<ll,1<<17> seg;
int N,M;

void solve() {
    int f,i,j,k,l,r,x,y;
    
    cin>>N>>M;
    FOR(i,N) {
        cin>>x;
        seg.update(i+1,x);
    }
    
    while(M--) {
        cin>>i;
        if(i==1) {
            cin>>l>>r;
            cout << seg.getval(l,r+1) << endl;
        }
        else if(i==2) {
            cin>>l>>r>>x;
            seg.update2(l,r+1,x);
        }
        else if(i==3) {
            cin>>x>>y;
            seg.update(x,y);
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