#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
map<int,int> M,MP;

template<class V, int ME> class BIT {
public:
    V bit[1<<ME],val[1<<ME];
    V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
    V add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
    V set(int e,V v) { add(e,v-val[e]);}
};
BIT<ll,20> bt,bt2;

ll ret;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    while(N--) {
        cin>>x>>y;
        if(M.count(x)==0) M[x]=x;
        if(M.count(y)==0) M[y]=y;
        MP[x]=MP[y]=0;
        swap(M[x],M[y]);
    }
    MP[0]=0;
    x=0;
    FORR(r,MP) r.second=x++;
    
    for(auto it=M.rbegin();it!=M.rend();it++) {
        ret += bt.total(MP[it->second]);
        bt.add(MP[it->second],1);
        ret += abs(it->second-it->first);
        bt2.add(MP[it->first],1);
    }
    for(auto it=M.rbegin();it!=M.rend();it++) {
        if(it->first<it->second) ret -= bt2.total(MP[it->second])-bt2.total(MP[it->first]);
        if(it->first>it->second) ret -= bt2.total(MP[it->first])-bt2.total(MP[it->second]);
    }
    cout<<ret<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}