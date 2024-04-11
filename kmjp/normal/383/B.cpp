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
int X[100010],Y[100010];
map<int, set<int> > MM;

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>M;
    ll ret=2*(N-1);
    int ma0=N,minn=1;
    
    
    FOR(i,M) {
        cin>>X[i]>>Y[i];
        if(X[i]==1) ma0=min(ma0,Y[i]-1);
        else MM[X[i]].insert(Y[i]);
    }
    
    int ng=0;
    vector<pair<int,int> > OK,OK2;
    
    OK.push_back(make_pair(1,ma0));
    ll prex=1;
    ITR(it,MM) {
        
        if(it->first!=prex+1) {
            j=OK.begin()->first;
            OK.clear();
            OK.push_back(make_pair(j,N));
        }
        
        //ITR(it2,OK) _P("(%d,%d)",it2->first,it2->second);
        //_P("::%d\n",it->first);
        
        OK2.clear();
        
        vector<pair<int,int> >::iterator oit=OK.begin();
        set<int>::iterator bit=it->second.begin();
        i=1;
        while(oit!=OK.end() && bit!=it->second.end()) {
            if(i>oit->first) oit->first=i;
            
            if(oit->first>oit->second) { oit++; continue; }
            if(*bit<oit->first) { bit++; continue;}
            if(*bit==oit->first) { bit++; oit->first++; continue;}
            OK2.push_back(make_pair(oit->first,*bit-1));
            i=*bit+1;
            bit++;
        }
        
        if(bit==it->second.end()) {
            while(oit!=OK.end()) {
                if(i>oit->first) oit->first=i;
                if(oit->first<=oit->second) break;
                oit++;
            }
            if(oit!=OK.end() && oit->first<=N) OK2.push_back(make_pair(oit->first,N));
        }
        
        swap(OK,OK2);
        if(OK.empty()) {
            cout << -1 << endl;
            return;
        }
        prex=it->first;
    }
    
    
    if(prex!=N) {
        j=OK.begin()->first;
        OK.clear();
        OK.push_back(make_pair(j,N));
    }
    
    if(OK.back().second<N) cout << -1 << endl;
    else cout << ret << endl;
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}