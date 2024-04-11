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

template<class V,int NV> class SegTree_2 {
public:
    V nolink;
    vector<V> val;
    vector<V> cur,sum;
    SegTree_2(){val.resize(NV*2); sum.resize(NV*2); cur.resize(NV*2); clear(); nolink=-1<<30;};
    void clear() { for(int i=0;i<NV*2;i++) val[i]=nolink,sum[i]=cur[i]=0; }
    
    V getval(int x,int y,int l,int r,int k) {
        x=max(l,x);
        y=min(r,y);
        if(r<=x || y<=l) return 0;
        if(x<=l && r<=y) return sum[k];
        return getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1)+cur[k]*(y-x);
    }
    V getval(int x,int y) { return getval(x,y,0,NV,1);}
    
    void update(int x,int y,int l,int r, V v,int k) {
        if(l>=r) return;
        x=max(l,x);
        y=min(r,y);
        if(x>=y) return;
        if(x<=l && r<=y) {
            if(val[k]!=nolink) {
                cur[k]+=abs(val[k]-v);
            }
            else {
                update(x,y,l,(l+r)/2,v,k*2);
                update(x,y,(l+r)/2,r,v,k*2+1);
            }
            if(k*2<NV*2) sum[k]=sum[k*2]+sum[k*2+1]+cur[k]*(r-l);
            else sum[k]=cur[k]*(r-l);
            val[k]=v;
        }
        else if(l < y && x < r) {
            if(val[k]!=nolink) {
                val[k*2]=val[k*2+1]=val[k];
                val[k]=nolink;
            }
            update(x,y,l,(l+r)/2,v,k*2);
            update(x,y,(l+r)/2,r,v,k*2+1);
            if(k*2<NV*2) sum[k]=sum[k*2]+sum[k*2+1]+cur[k]*(r-l);
            else sum[k]=cur[k]*(r-l);
        }
    }
    void update(int x,int y,V v) { update(x,y,0,NV,v,1);}
    
};

int N,M;
SegTree_2<ll,1<<20> st;

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,N) st.val[i+(1<<20)]=i+1;
    FOR(i,1<<20) st.val[i]=st.nolink;
    
    while(M--) {
        cin>>i>>x>>y;
        if(i==1) {
            cin>>k;
            st.update(x-1,y,k);
        }
        else {
            _P("%lld\n",st.getval(x-1,y));
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