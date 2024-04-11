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

int N;
int X[100001],Y[100001];
vector<int> XX[100002],YY[100002];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) {
        cin>>X[i]>>Y[i];
        XX[X[i]].push_back(Y[i]);
        YY[Y[i]].push_back(X[i]);
    }
    FOR(i,100001) sort(XX[i].begin(),XX[i].end());
    FOR(i,100001) sort(YY[i].begin(),YY[i].end());
    
    int ret=0;
    FOR(i,N) {
        if(XX[X[i]].size()<YY[Y[i]].size()) {
            FOR(x,XX[X[i]].size()) if(XX[X[i]][x]>Y[i]) {
                l=XX[X[i]][x]-Y[i];
                if(binary_search(XX[X[i]+l].begin(),XX[X[i]+l].end(),Y[i]) &&
                   binary_search(XX[X[i]+l].begin(),XX[X[i]+l].end(),Y[i]+l)) ret++;
            }
        }
        else {
            FOR(y,YY[Y[i]].size()) if(YY[Y[i]][y]>X[i]) {
                l=YY[Y[i]][y]-X[i];
                if(binary_search(XX[X[i]].begin(),XX[X[i]].end(),Y[i]+l) &&
                   binary_search(XX[X[i]+l].begin(),XX[X[i]+l].end(),Y[i]+l)) ret++;
            }
        }
    }
    cout << ret << endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}