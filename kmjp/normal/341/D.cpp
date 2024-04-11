#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;

template<class V,int MA> class BIT_2d {
public:
    V val[1<<MA][1<<MA];
    BIT_2d(){ZERO(val);};
    V total(int x,int y) {
        V s=0;
        for(int i=x+1;i>0;i-=i&-i) for(int j=y+1;j>0;j-=j&-j) s^=val[i-1][j-1];
        return s;
    }
    void update(int x,int y,ll v) {
        for(int i=x+1;i<=1<<MA;i+=i&-i) for(int j=y+1;j<=1<<MA;j+=j&-j) val[i-1][j-1]^=v;
    }
};
BIT_2d<ll,10> bit[2][2];

void solve() {
    int i,j,k,l,r,x1,y1,x2,y2; string s;
    ll v;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>j>>x1>>y1>>x2>>y2;
        if(j==1) {
            ll ret=0;
            ret ^= bit[x2%2][y2%2].total(x2,y2);
            ret ^= bit[x2%2][(y1-1)%2].total(x2,y1-1);
            ret ^= bit[(x1-1)%2][y2%2].total(x1-1,y2);
            ret ^= bit[(x1-1)%2][(y1-1)%2].total(x1-1,y1-1);
            cout<<ret<<endl;
        }
        if(j==2) {
            cin>>v;
            bit[x1%2][y1%2].update(x1,y1,v);
            bit[(x2+1)%2][y1%2].update(x2+1,y1,v);
            bit[x1%2][(y2+1)%2].update(x1,y2+1,v);
            bit[(x2+1)%2][(y2+1)%2].update(x2+1,y2+1,v);
        }
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}