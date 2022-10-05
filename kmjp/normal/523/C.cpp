#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S,T;
int L=-1,R=-1;

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>S>>T;
    
    x=0;
    FOR(i,T.size()) {
        if(T[i]==S[x]) {
            x++;
            if(x==S.size()) {
                L=i;
                break;
            }
        }
    }
    x=S.size()-1;
    for(i=T.size()-1;i>=0;i--) {
        if(T[i]==S[x]) {
            x--;
            if(x==-1) {
                R=i;
                break;
            }
        }
    }
    if(L>=0 && R>=0 && L<=R) cout<<R-L<<endl;
    else cout<<0<<endl;
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}