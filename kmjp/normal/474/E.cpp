#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class SegTree_1 {
public:
    vector<V> val,from;
    static V const def=0;
    SegTree_1(){val=vector<V>(NV*2,def);from=vector<V>(NV*2,def);};
    
    pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
        if(r<=x || y<=l) return make_pair(0,-1);
        if(x<=l && r<=y) return make_pair(val[k],from[k]);
        pair<V,int> p1=getval(x,y,l,(l+r)/2,k*2);
        pair<V,int> p2=getval(x,y,(l+r)/2,r,k*2+1);
        if(p1.first>p2.first) return p1;
        return p2;
    }
    void update(int entry, V v,int f) {
        entry += NV;
        val[entry]=v;
        from[entry]=f;
        while(entry>1){
            entry>>=1;
            val[entry]=val[entry*2+(val[entry*2]<val[entry*2+1])];
            from[entry]=from[entry*2+(val[entry*2]<val[entry*2+1])];
        }
    }
};

int N,D;
ll H[100500];
map<ll,int> M;
vector<ll> K;
int ma[100500],cur[100500],pre[100500];

SegTree_1<int,1<<20> st;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>D;
    M[0]=M[1LL<<30]=0;
    FOR(i,N) cin>>H[i], M[H[i]]++;
    i=0;
    ITR(it,M) it->second=i++, K.push_back(it->first);
    
    FOR(i,N) {
        j=M[H[i]];
        cur[i]=1;
        pre[i]=-1;
        // upper
        k=lower_bound(K.begin(),K.end(),H[i]+D)-K.begin();
        pair<ll,int> v=st.getval(k,1<<18);
        if(cur[i]<v.first+1) cur[i]=v.first+1, pre[i]=v.second;
        
        // lower
        k=upper_bound(K.begin(),K.end(),max(0LL,H[i]-D))-K.begin();
        v=st.getval(0,k);
        if(cur[i]<v.first+1) cur[i]=v.first+1, pre[i]=v.second;
        
        if(cur[i]>ma[j]) ma[j]=cur[i], st.update(j,ma[j],i);
    }
    
    x=max_element(cur,cur+N)-cur;
    _P("%d\n",cur[x]);
    vector<int> V;
    while(x>=0) V.push_back(x+1), x=pre[x];
    
    FOR(i,V.size()) _P("%d ",V[V.size()-1-i]);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}