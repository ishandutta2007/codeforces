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

ll N,A,B;
ll mo=1000000007;
ll PP[2][65];
int mm;
map<pair<ll,ll>,ll> M[100];

ll dpdp(ll L,ll R,int m) {
    if(m==0) return L==R;
    
    ll ret=0,a;
    if(m==1) {
        if((R-L)%(A-N)) return 0;
        ll a1=(R-L)/(A-N);
        ll a0=A-a1*N;
        return a0>=0 && a1>=0;
    }
    
    FOR(a,min(L/PP[0][m],R/PP[1][m])+1) {
        ll L2=L-a*PP[0][m];
        ll R2=R-a*PP[1][m];
        if(L2<0 || R2<0 || L2>R2) break;
        if(L2==0) {
            ret += L2==R2;
        }
        else {
            if(R2/L2 > PP[1][m]/PP[0][m]) continue;
            ret += dpdp(L2,R2,m-1);
        }
        ret %= mo;
    }
    return ret;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>A>>B;
    
    if(N==A) {
        if(A!=B) return _P("0\n");
        if(N==1) return _P("inf\n");
        return _P("2\n");
    }
    if(N>A) return _P("%d\n",A==B);
    
    PP[0][0]=PP[1][0]=1;
    FOR(mm,100) {
        PP[0][mm+1]=PP[0][mm]*N;
        PP[1][mm+1]=PP[1][mm]*A;
        if(PP[0][mm+1]>A || PP[1][mm+1]>B || PP[0][mm+1]/N!=PP[0][mm] || PP[1][mm+1]/A!=PP[1][mm]) break;
    }
    cout << dpdp(A,B,mm) << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}