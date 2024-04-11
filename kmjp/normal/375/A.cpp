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

string S;

int mod7(string S) {
    int i,j=0;
    FOR(i,S.size()) {
        j=j*10+(S[i]-'0');
        if(j>10000) j%=7;
    }
    return j%7;
    
}

void solve() {
    int f,i,j,k,l,x,y,a[256];
    cin>>S;
    int L=S.size();
    x=0;
    ZERO(a);
    x=L-1;
    a['1']=a['6']=a['8']=a['9']=1;
    for(i=L-1;i>=0;i--) {
        if(a[S[i]]) a[S[i]]=0;
        else swap(S[x--],S[i]);
    }
    S=S.substr(4);
    string T="1689";
    do {
        if(mod7(T+S)==0) {
            cout << T+S << endl;
            return;
        }
    } while(next_permutation(T.begin(), T.end()));
    
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}