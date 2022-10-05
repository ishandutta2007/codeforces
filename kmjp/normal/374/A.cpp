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

int N,M,I,J,A,B;

void solve() {
    int f,i,j,k,l,x,y,r;
    cin>>N>>M>>I>>J>>A>>B;
    r=1<<30;
    
    FOR(i,4) {
        x=(i%2)?1:N;
        y=((i/2)%2)?1:M;
        x=abs(I-x);
        y=abs(J-y);
        
        if(x%A) continue;
        if(y%B) continue;
        
        if(((x/A)%2)!=((y/B)%2)) continue;
        l=max(x/A,y/B);
        if(x==0 && l && A>=N) continue;
        if(y==0 && l && B>=M) continue;
        
        r=min(r,l);
    }
    
    if(r==1<<30) cout << "Poor Inna and pony!" << endl;
    else cout << r << endl;
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}