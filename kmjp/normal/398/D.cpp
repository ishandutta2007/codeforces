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

const int D=555;
int N,M,Q;
int state[50500],cnt[50500];
unordered_set<int> F[50500],H[50500];

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N>>M>>Q;
    cin>>i;
    while(i--) cin>>y, state[y-1]=1;
    while(M--) {
        cin>>x>>y;
        F[x-1].insert(y-1);
        F[y-1].insert(x-1);
    }

    FOR(i,N) {
        if(state[i]&&F[i].size()<D) ITR(it,F[i]) cnt[*it]++;
        if(F[i].size()>=D) ITR(it,F[i]) H[*it].insert(i);
    }

    while(Q--) {
        cin>>s>>x;
        x--;
        if(s[0]=='O' || s[0]=='F') {
            if(F[x].size()<D) {
                if(s[0]=='O') { ITR(it,F[x]) cnt[*it]++;}
                if(s[0]=='F') { ITR(it,F[x]) cnt[*it]--;}
            }
            state[x]^=1;
        }
        else if(s[0]=='A') {
            cin>>y;
            y--;
            if(F[x].size()==D-1) {
                ITR(it,F[x]) {
                    cnt[*it]-=state[x];
                    H[*it].insert(x);
                }
            }
            if(F[y].size()==D-1) {
                ITR(it,F[y]) {
                cnt[*it]-=state[y];
                H[*it].insert(y);
                }
            }
            F[x].insert(y);
            F[y].insert(x);
            if(F[x].size()<D) cnt[y]+=state[x];
            else H[y].insert(x);
            if(F[y].size()<D) cnt[x]+=state[y];
            else H[x].insert(y);
        }
        else if(s[0]=='D') {
            cin>>y;
            y--;
            if(F[x].size()<D) cnt[y]-=state[x];
            else H[y].erase(x);
            if(F[y].size()<D) cnt[x]-=state[y];
            else H[x].erase(y);
            F[x].erase(y);
            F[y].erase(x);

            if(F[x].size()==D-1) {
                ITR(it,F[x]) H[*it].erase(x), cnt[*it]+=state[x];
            }
            if(F[y].size()==D-1) {
                ITR(it,F[y]) H[*it].erase(y), cnt[*it]+=state[y];
            }
        }
        else {
            int ret=cnt[x];
            ITR(it,H[x]) if(state[*it]) ret++;
            cout<<ret<<endl;
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