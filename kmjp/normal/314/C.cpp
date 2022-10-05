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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef signed long long ll;
typedef unsigned long long u64;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

ll mo=1000000007;

template<class V, int ME> class BIT {
public:
    V* bit;
    BIT(){bit=new V[ME];memset(bit,0,sizeof(V)*ME);}
    
    V total(int entry) {
        V s=0;
        entry++;
        while(entry>0) {
            s+=bit[entry-1];
            entry -= entry & -entry;
        }
        return s % mo;
    }
    void update(int entry, V val) {
        entry++;
        while(entry <= ME) {
            bit[entry-1] = (bit[entry-1] + val) % mo;
            entry += entry & -entry;
        }
    }
};
BIT<ll,1<<20> bit;

void solve() {
    int f,r,i,j,k,l, x,y;
    ll ret = 1;
    
    cin>>j;
    //bit.update(0,1);
    FOR(i,j) {
        cin>>x;
        bit.update(x, (x+bit.total(x)*x-(bit.total(x)-bit.total(x-1)))%mo);
    }
    
    cout << bit.total(1<<20) << endl;

    return;
}

int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}