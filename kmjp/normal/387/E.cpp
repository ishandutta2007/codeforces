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

template<class V, int ME> class BIT {
public:
    V bit[1<<ME];

    int lower_bound(V val) {
        V tv=0;
        int i,ent=0;
        FOR(i,ME) if(tv+bit[ent+(1<<(ME-1-i))-1]<val) tv+=bit[ent+(1<<(ME-1-i))-1], ent += (1<<(ME-1-i));
        return ent;
    }
    V total(int entry) {
        V s=0;
        entry++;
        while(entry>0) s+=bit[entry-1], entry -= entry & -entry;
        return s;
    }
    void update(int entry, V val) {
        entry++;
        while(entry <= (1<<ME)) bit[entry-1] += val, entry += entry & -entry;
    }
};
BIT<int,21> cnt,ava;

int N,K;
int rem[1000003];
int ord[1000003];

void solve() {
    int f,i,j,k,l,x,y,r;
    ll ret=0;
    
    
    cin>>N>>K;
    FOR(i,N) {
        cin>>x;
        ord[x]=i+1;
    }
    FOR(i,K) {
        cin>>x;
        rem[x]=1;
    }
    
    FOR(i,N) cnt.update(i+1,1);
    ava.update(1,1);
    ava.update(N+1,1);
    
    FOR(i,N) {
        if(rem[i+1]) {
            cnt.update(ord[i+1],-1);
            ava.update(ord[i+1],1);
        }
        else {
            x = ava.total(ord[i+1]);
            int a=ava.lower_bound(x);
            int b=ava.lower_bound(x+1);
            ret += cnt.total(b-1)-cnt.total(a-1);
            cnt.update(ord[i+1],-1);
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