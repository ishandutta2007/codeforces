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

int L;
string S,T;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>S;
    L=S.size();
    int id=-1;
    FOR(i,L) if(S[i]%2==0) {
        if(id==-1) id=i;
        else {
            if((S[L-1]-'0')*100+(S[i]-'0')*10+(S[id]-'0') < (S[id]-'0')*100+(S[L-1]-'0')*10+(S[i]-'0'))
                id=i;
        }
    }
    if(id==-1) _P("-1\n");
    else {
        swap(S[id],S[L-1]);
        cout<<S<<endl;
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}