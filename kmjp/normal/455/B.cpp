#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

ll N,K;
vector<string> S;

class Trie {
public:
    vector<vector<int> > V;
    int find(string s) {
        int cur=0;
        ITR(it,s) if((cur=V[cur][*it])==0) return -1;
        return cur;
    }
    void create(vector<string> S) {
        V.clear();
        V.push_back(vector<int>(256));
        sort(S.begin(),S.end());
        ITR(it,S) {
            int cur=0;
            ITR(c,(*it)) {
                if(V[cur][*c]==0) V.push_back(vector<int>(256)),V[cur][*c]=V.size()-1;
                cur=V[cur][*c];
            }
        }
    }
};

Trie t;

bool winwin(int cur) {
    int i;
    FOR(i,256) if(t.V[cur][i]!=0) {
        if(winwin(t.V[cur][i])==false) return true;
    }
    return false;
}

bool loselose(int cur) {
    int i,num=0;
    
    FOR(i,256) if(t.V[cur][i]!=0) {
        
        if(loselose(t.V[cur][i])==false) return true;
        if(loselose(t.V[cur][i])==true) num++;
    }
    if(num) return false;
    return true;
}

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>K;
    FOR(i,N) {
        string s;
        cin>>s;
        S.push_back(s);
    }
    t.create(S);
    bool b1=winwin(0);
    bool b2=loselose(0);
    if(!b1) {
        cout << "Second" << endl;
    }
    else {
        if(b2) {
            cout << "First" << endl;
        }
        else {
            if(K%2) cout << "First" << endl;
            else cout << "Second" << endl;
        }
    }
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}