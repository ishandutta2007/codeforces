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
int N[3],P[3],NN[3];
ll R;

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>S;
    cin>>N[0]>>N[1]>>N[2];
    cin>>P[0]>>P[1]>>P[2];
    cin>>R;
    FOR(i,S.size()) {
        if(S[i]=='B') NN[0]++;
        if(S[i]=='S') NN[1]++;
        if(S[i]=='C') NN[2]++;
    }
    
    ll res=0;
    while(1) {
        if((!NN[0] || (N[0]==0)) && (!NN[1] || (N[1]==0)) && (!NN[2] || (N[2]==0))) {
            x=P[0]*NN[0]+P[1]*NN[1]+P[2]*NN[2];
            res += R/x;
            break;
        }
        x=0;
        FOR(i,3) {
            if(N[i]>=NN[i]) N[i]-=NN[i];
            else x+=P[i]*(NN[i]-N[i]),N[i]=0;
        }
        if(R<x) break;
        R-=x;
        res++;
    }
    
    cout << res << endl;
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}