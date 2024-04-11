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

ll W,H,N;
set<int> XX,YY;
multiset<int> WW,HH;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>W>>H>>N;
    XX.insert(0);
    XX.insert(W);
    YY.insert(0);
    YY.insert(H);
    WW.insert(W);
    HH.insert(H);
    
    FOR(i,N) {
        cin>>s>>x;
        set<int>::iterator it;
        
        if(s[0]=='V') {
            it=XX.lower_bound(x);
            y=*it;
            it--;
            j=*it;
            WW.erase(WW.lower_bound(y-j));
            WW.insert(y-x);
            WW.insert(x-j);
            XX.insert(x);
        }
        else {
            it=YY.lower_bound(x);
            y=*it;
            it--;
            j=*it;
            HH.erase(HH.lower_bound(y-j));
            HH.insert(y-x);
            HH.insert(x-j);
            YY.insert(x);
        }
        auto a=WW.rbegin();
        auto b=HH.rbegin();
        
        cout<<1LL*(*a)*(*b)<<endl;
        
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}