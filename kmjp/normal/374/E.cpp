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


int N,M;
int BX[2010],BY[2010];
int RX[2010],RY[2010];
int tim[2010][2010];
map<int,vector<int> > R,B;

void generate(map<int,vector<int> >& LS, vector<pair<int,pair<int,int> > >& VV,double le) {
    int i,j,x,ny1,ny2;
    
    VV.clear();
    ITR(it,LS) {
        x=it->first;
        ITR(it2,it->second) {
            ny1 = *it2 - 2*le;
            ny2 = *it2 + 2*le;
            
            bool conn = !VV.empty();
            if(!VV.empty()) {
                if(VV.back().first != x) conn=false;
                if(VV.back().second.second < ny1) conn=false;
            }
            if(conn) VV.back().second.second = ny2;
            else VV.push_back(make_pair(x,make_pair(ny1,ny2)));
        }
    }
}

int okok(int le) {
    int i,j,r,b;
    static int vis[2001][2001];
    vector<pair<int,pair<int,int> > > BV,RV;
    generate(B,BV,le);
    generate(R,RV,le);
    
    ZERO(vis);
    FOR(b,BV.size()) {
        vector<int> rr;
        FOR(r,RV.size()) {
            if(BV[b].first < RV[r].second.first || BV[b].first > RV[r].second.second) continue;
            if(RV[r].first < BV[b].second.first || RV[r].first > BV[b].second.second) continue;
            ITR(itr,rr) {
                if(++vis[*itr][r]>=2) return 1;
            }
            rr.push_back(r);
        }
    }
    
    return 0;
}


void solve() {
    int f,i,j,k,l,x,y,r;
    
    cin>>N>>M;
    FOR(i,N) {
        cin>>x>>y;
        B[x+y].push_back(x-y);
    }
    FOR(i,M) {
        cin>>x>>y;
        R[x-y].push_back(x+y);
    }
    
    if(B.size()<2 || R.size()<2) return _P("Poor Sereja!\n");
    ITR(it,B) sort(it->second.begin(),it->second.end());
    ITR(it,R) sort(it->second.begin(),it->second.end());
    
    int ll=0,rr=1<<25,p;
    FOR(i,60) {
        p=(ll+rr)/2;
        if(okok(p)) rr=p;
        else ll=p;
    }
    _P("%d\n",rr);
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}