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
    BIT(){clear();};
    void clear() {ZERO(bit);};

    //V* bit;
    //BIT(){bit=new V[1<<ME];memset(bit,0,sizeof(V)*(1<<ME));}

    int lower_bound(V val) {
        V tv=0;
        int i,ent=0;
        //FOR(i,ME) if(tv+bit[ent+(1<<(ME-1-i))]<val) tv+=bit[ent+(1<<(ME-1-i))], ent += (1<<(ME-1-i));
        FOR(i,ME) {
            //_P("%d  %d %d %d\n",i,ent,tv,bit[ent+(1<<(ME-1-i))-1]);
            if(tv+bit[ent+(1<<(ME-1-i))-1]<val) tv+=bit[ent+(1<<(ME-1-i))-1], ent += (1<<(ME-1-i));
        }
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

BIT<int,20> bt;

int N,M;
int A[1000002],B[1000002];
int NG[1000002];
vector<int> V,D;

void solve() {
    int f,i,j,k,l,x,y,r;
    
    cin>>N>>M;
    FOR(i,M) cin>>A[i];
    A[M]=N;
    NG[0]=1;
    y=0;
    V.push_back(2);
    
    FOR(i,N) bt.update(i+1,1);
    
    FOR(i,N) {
        cin>>x;
        if(x>=0) V.push_back(x),y++;
        else {
            f = lower_bound(A,A+M,y+1) - A;
            if(f>0) {
                D.push_back(f);
                y-=f;
            }
        }
    }
    //_P("%d %d\n",D.size(),y);
    
    if(y==0) {
        _P("Poor stack!\n");
    }
    else {
        FOR(i,D.size()) {
            //_P("%d\n",D[i]);
            for(f=D[i]-1;f>=0;f--) {
                j = bt.lower_bound(A[f]);
                NG[j]=1;
                //_P("  del %d %d\n",j,bt.total(j));
                bt.update(j,-1);
            }
        }
        FOR(i,V.size()) if(NG[i]==0) _P("%d",V[i]);
        _P("\n");
    }
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}