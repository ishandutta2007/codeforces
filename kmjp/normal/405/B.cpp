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

int L;
string S;

void solve() {
    int f,i,j,k,l,x,y,r;
    
    cin>>L>>S;
    f=0;
    FOR(i,L) {
        if(S[i]!='.') continue;
        l=i-1;
        r=i+1;
        while(l>=0) {
            if(S[l]=='R') break;
            else if(S[l]=='L') l=-1;
            else l--;
        }
        while(r<L) {
            if(S[r]=='L') break;
            else if(S[r]=='R') r=L;
            else r++;
        }
        if(l<0 && r>=L) f++;
        if(l>=0 && r<L && i-l==r-i) f++;
    }
    
    cout<<f<<endl;
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}