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
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

void dfs(vector<pair<int,int> > P, vector<pair<int,int> > C) {
    int i,x,y;
    vector<pair<int,int> > P2;
    vector<int> P3;

    //FOR(i,P.size()) _P("<%d:%d>",P[i].first,P[i].second);
    
    FOR(i,P.size()) {
        if(!P2.empty() && abs(P2[P2.size()-1].second-P[i].first)==1) P2[P2.size()-1].second=P[i].second;
        else P2.push_back(P[i]);
    }
    
    /*FOR(i,P2.size()) _P("%d:%d ",P2[i].first,P2[i].second);
    FOR(i,C.size()) _P("[%d:%d]",C[i].first,C[i].second);
    _P("\n");*/
    
    if(P2.size()==1 && P2[0].first==1) {
        _P("%d\n",C.size());
        FOR(i,C.size()) _P("%d %d\n",C[C.size()-1-i].first,C[C.size()-1-i].second);
        exit(0);
    }
    if(C.size()>=3) return;
    
    y=1;
    FOR(x,P2.size()) P3.push_back(y),P3.push_back(y+abs(P2[x].second-P2[x].first)),y+=1+abs(P2[x].second-P2[x].first);
    FOR(x,P3.size()) for(y=x+1;y<P3.size();y++) {
        if(P3[x]==P3[y]) continue;
        if(x%2 && P3[x]==P3[x-1]) continue;
        if(y%2==0 && P3[y+1]==P3[y]) continue;
        C.push_back(make_pair(P3[x],P3[y]));
        if(x%2==0 && y%2==1) {
            P=P2;
            for(i=x/2;i<=y/2;i++) P[i]=make_pair(P2[x/2+y/2-i].second,P2[x/2+y/2-i].first);
        }
        else  {
            P.clear();
            FOR(i,x/2) P.push_back(P2[i]);
            if(x%2==0 && y%2==0) {
                P.push_back(make_pair(P2[y/2].first,P2[y/2].first));
                for(i=y/2-1;i>=x/2;i--) P.push_back(make_pair(P2[i].second,P2[i].first));
                P.push_back(make_pair(P2[y/2].first+((P2[y/2].second>P2[y/2].first)?1:-1),P2[y/2].second));
            }
            else if(x%2==1 && y%2==0) {
                P.push_back(make_pair(P2[x/2].first,P2[x/2].second+((P2[x/2].second>P2[x/2].first)?-1:1)));
                P.push_back(make_pair(P2[y/2].first,P2[y/2].first));
                for(i=y/2-1;i>=x/2+1;i--) P.push_back(make_pair(P2[i].second,P2[i].first));
                P.push_back(make_pair(P2[x/2].second,P2[x/2].second));
                P.push_back(make_pair(P2[y/2].first+((P2[y/2].second>P2[y/2].first)?1:-1),P2[y/2].second));
            }
            else {
                P.push_back(make_pair(P2[x/2].first,P2[x/2].second+((P2[x/2].second>P2[x/2].first)?-1:1)));
                for(i=y/2;i>=x/2+1;i--) P.push_back(make_pair(P2[i].second,P2[i].first));
                P.push_back(make_pair(P2[x/2].second,P2[x/2].second));
            }
            for(i=y/2+1;i<P2.size();i++) P.push_back(P2[i]);
        }
        dfs(P,C);
        C.pop_back();
    }
    
}

void solve() {
    int f,i,j,k,l, x,y,N;
    vector<pair<int,int> > P;
    
    cin>>N;
    FOR(i,N) cin>>x,P.push_back(make_pair(x,x));
    
    dfs(P,vector<pair<int,int> >());
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}