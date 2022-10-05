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

const double EPS=1e-20;

template<class C> C veccross(pair<C,C> p1,pair<C,C> p2,pair<C,C> p3) {
    p3.first-=p1.first;p2.first-=p1.first;
    p3.second-=p1.second;p2.second-=p1.second;
    return p3.first*p2.second-p2.first*p3.second;
}

template<class C> vector<int> convex_hull(vector< pair<C, C> >& vp) {
    vector<pair<pair<C, C>, int> > sorted;
    vector<int> res;
    int i,k=0,rb;
    
    if(vp.size()<=2) {
        if(vp.size()>=1) res.push_back(0);
        if(vp.size()>=2 && vp[0]!=vp[1]) res.push_back(1);
        return res;
    }
    
    FOR(i,vp.size()) sorted.push_back(make_pair(vp[i],i));
    sort(sorted.begin(),sorted.end());
    reverse(sorted.begin(),sorted.end());
    
    res.resize(vp.size()*2);
    FOR(i,vp.size()) {
        while(k>1 && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=-EPS) k--;
        res[k++]=sorted[i].second;
    }
    res.resize(k);
    return res;
}

int N;
int S[303030],T[303030];
int ma[11000];
multiset<int> SS[10100];
vector<int> R;

void solve() {
    int i,j,k,l,r,x,y,s;
    
    cin>>N;
    FOR(i,N) {
        cin>>S[i]>>T[i];
        if(ma[S[i]]<T[i]) ma[S[i]]=T[i],SS[S[i]].clear();
        if(ma[S[i]]==T[i]) SS[S[i]].insert(i+1);
    }
    
    vector<pair<double,double> > V;
    y=-1;
    for(s=10000;s>=1;s--) if(ma[s]>0 && (y==-1 || ma[s]>ma[y])) V.push_back(make_pair(1.0/s,1.0/ma[s])), y=s;
    
    vector<int> RR=convex_hull(V);
    FORR(r,RR) FORR(r2,SS[(int)floor(1.0/V[r].first+0.1)]) R.push_back(r2);
    sort(R.begin(),R.end());
    
    FORR(r,R) _P("%d ",r);
    _P("\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}