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

void solve() {
    int f,i,j,k,l, x,y,r,t;
    
    cin>>S;
    l=S.size();
    //rotate
    FOR(x,l-1) if(S[x]=='1' && S[x+1]=='0') break;
    if(x!=l-1) S=S.substr(x+1)+S.substr(0,x+1);
    
    vector<int> P;
    FOR(i,l) if(S[(l+i-1)%l] != S[i]) P.push_back(i);
    vector<int> P2=P;
    r=0;
    k=P.size();
    x=-1;
    FOR(i,k) {
        if((P2[i]+1)%l != P2[(i+1)%k]%l) {
            r++;
            P[i]=P[(i+1)%k]=-1;
            if(x<0) x=i;
        }
    }
    if(x<0) {
        r+=k/2;
    }
    else {
        FOR(y,P.size()) {
            if(P[(x+y)%k]==-1) continue;
            t=0;
            while(y+t<k && P[(x+y+t)%k]!=-1) t++;
            r+=(t+1)/2;
            y+=t-1;
        }
    }
    
    /*
    cout << S << endl;
    ITR(it,P) _P("%d ",*it);
    _P("\n");
    ITR(it,P2) _P("%d ",*it);
    _P("\n");
    */
    cout << r << endl;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}