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

int N;
int B[1010];

string dodo(string c,int d,bool istop=false) {
    int l=c.size();
    int x,i;
    
    if(d<0) return "*";
    if(l==0) return "*";
    
    string s = dodo(c.substr(1),d-(c[0]-'0'));
    if(s!="*") return c.substr(0,1)+s;
    for(x=c[0]-'0'+1;x<=9;x++) {
        if(d-x<0) break;
        if((l-1)*9<d-x) continue;
        s=c;
        s[0]='0'+x;
        d-=x;
        for(i=l-1;i>0;i--) {
            s[i]='0'+min(9,d);
            d-=min(9,d);
        }
        return s;
    }
    if(!istop) return "*";
    while(1) {
        for(x=1;x<=9;x++) {
            if(x<=d && l*9+x>=d) {
                s="0";
                s+=c;
                s[0]+=x;
                d-=x;
                for(i=l;i>0;i--) {
                    s[i]='0'+min(9,d);
                    d-=min(9,d);
                }
                return s;
            }
        }
        c=c+"0";
        l=c.size();
    }
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    string c="0";
    FOR(i,N) {
        cin>>B[i];
        c=dodo(c,B[i],true);
        cout<<c<<endl;
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}