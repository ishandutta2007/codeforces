#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

char hoge[3][12]={
"qwertyuiop",
"asdfghjkl;",
"zxcvbnm,./",
};

void solve() {
    int i,j,k,l,r,x,y; string s,t;
    cin>>s>>t;
    if(s=="L") x=1;
    else x=-1;
    FOR(i,t.size()) {
        FOR(j,3) FOR(k,11) {
            if(t[i]==hoge[j][k]) {
                t[i]=hoge[j][k+x];
                goto out;
            }
        }
        out:
        ;
    }
    cout << t << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}