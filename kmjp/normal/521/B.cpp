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

int M;
int X[101000],Y[101000];
map<pair<int,int>,int> P;
ll pm[101000];
set<int> up[101000],down[101000];
set<int> S;
ll mo=1000000009;

bool okok(int x) {
    bool ok=true;
    ITR(it,up[x]) ok &= down[*it].size()>=2;
    return ok;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>M;
    pm[0]=1;
    FOR(i,M) {
        pm[i+1]=pm[i]*M%mo;
        cin>>X[i]>>Y[i];
        P[make_pair(X[i],Y[i])]=i;
    }
    FOR(i,M) {
        for(j=-1;j<=1;j++) if(P.count(make_pair(X[i]+j,Y[i]+1))) {
            up[i].insert(P[make_pair(X[i]+j,Y[i]+1)]);
            down[P[make_pair(X[i]+j,Y[i]+1)]].insert(i);
        }
    }
    
    FOR(i,M) if(okok(i)) S.insert(i);
    ll ret=0;
    FOR(i,M) {
        if(i%2) x=*S.begin();
        else x=*S.rbegin();
        S.erase(x);
        ret += x*pm[M-1-i]%mo;
        
        ITR(it,up[x]) {
            y=*it;
            down[y].erase(x);
            if(okok(y)) S.insert(y);
            else S.erase(y);
            ITR(it2,down[y]) {
                if(okok(*it2)) S.insert(*it2);
                else S.erase(*it2);
            }
        }
        ITR(it,down[x]) {
            y=*it;
            up[y].erase(x);
            if(okok(y)) S.insert(y);
            else S.erase(y);
        }
    }
    cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}