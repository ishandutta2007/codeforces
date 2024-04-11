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

string S,T;
int A,B,L;
int p10[1000001];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>S>>A>>B;
    L=S.size();
    
    ll v1=0,v2=0;
    p10[0]=1;
    T=S;
    FOR(i,L) S[i]-='0';
    FOR(i,L) p10[i+1]=p10[i]*10%B, v2=(v2+p10[i]*S[L-1-i])%B;
    
    FOR(i,L-1) {
        v1=(v1*10+S[i])%A;
        v2=(v2+B-p10[L-1-i]*S[i]%B)%B;
        if(v1==0 && v2==0 && S[i+1]!=0) {
            cout << "YES" <<endl;
            cout << T.substr(0,i+1) <<endl;
            cout << T.substr(i+1) <<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}