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

string S;
int dif;
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    FOR(y,8) {
        cin>>S;
        FOR(x,8) {
            if(S[x]=='q') dif-=9;
            if(S[x]=='r') dif-=5;
            if(S[x]=='b') dif-=3;
            if(S[x]=='n') dif-=3;
            if(S[x]=='p') dif-=1;
            if(S[x]=='Q') dif+=9;
            if(S[x]=='R') dif+=5;
            if(S[x]=='B') dif+=3;
            if(S[x]=='N') dif+=3;
            if(S[x]=='P') dif+=1;
        }
    }
    
    if(dif>0) cout<<"White"<<endl;
    else if(dif<0) cout<<"Black"<<endl;
    else cout<<"Draw"<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}