#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int dfs(set<pair<ll,ll> >& XS,set<pair<ll,ll> >& YS) {
    int N=XS.size(),i;
    if(XS.empty()) return 0;
    set<pair<ll,ll> >::iterator xa=XS.begin();
    set<pair<ll,ll> >::iterator ya=YS.begin();
    set<pair<ll,ll> >::iterator xb=XS.end();
    set<pair<ll,ll> >::iterator yb=YS.end();
    set<pair<ll,ll> >::iterator n,n2;
    set<pair<ll,ll> > NXS,NYS;
    
    xb--; yb--;
    
    FOR(i,N-1) {
        set<pair<ll,ll> >::iterator r;
        
        n=xa;n++;
        if(n->first>xa->first+1) {
            for(xa=XS.begin();xa!=n;) {
                NXS.insert(*xa);
                NYS.insert(make_pair(xa->second,xa->first));
                YS.erase(make_pair(xa->second,xa->first));
                XS.erase(xa++);
            }
            return dfs(XS,YS)+dfs(NXS,NYS);
        }
        n=xb;n--;
        if(xb->first>n->first+1) {
            n=xb;
            for(;n!=XS.end();) {
                NXS.insert(*n);
                NYS.insert(make_pair(n->second,n->first));
                YS.erase(make_pair(n->second,n->first));
                XS.erase(n++);
            }
            return dfs(XS,YS)+dfs(NXS,NYS);
        }
        n=ya;n++;
        if(n->first>ya->first+1) {
            for(ya=YS.begin();ya!=n;) {
                NYS.insert(*ya);
                NXS.insert(make_pair(ya->second,ya->first));
                XS.erase(make_pair(ya->second,ya->first));
                YS.erase(ya++);
            }
            return dfs(XS,YS)+dfs(NXS,NYS);
        }
        n=yb;n--;
        if(yb->first>n->first+1) {
            n=yb;
            for(;n!=YS.end();) {
                NYS.insert(*n);
                NXS.insert(make_pair(n->second,n->first));
                XS.erase(make_pair(n->second,n->first));
                YS.erase(n++);
            }
            return dfs(XS,YS)+dfs(NXS,NYS);
        }
        xa++, ya++, xb--, yb--;
    }
    return 1;
    
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    ll xx,yy;
    set<pair<ll,ll> > XS,YS;
    
    cin>>i;
    while(i--) {
        cin>>xx>>yy;
        xx+=1e9+1;
        yy+=1e9+1;
        XS.insert(make_pair(xx,yy));
        YS.insert(make_pair(yy,xx));
    }
    cout << dfs(XS,YS) << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}