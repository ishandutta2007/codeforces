#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

string s;
ll solve(string s){
    int n=s.length();
    ll ans=1988;
    FORD(i,n-1,4){
        ll mul=1,add=0;
        REP(j,i,n){
            mul=10*mul;
            add=10*add+s[j]-'0';
        }
        ll nx=max(mul+ans-add,0LL)/mul;
        ans=nx*mul+add;
    }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    int test;
    cin>>test;
    while (test--){
        cin>>s;
        cout<<solve(s)<<'\n';
    }
}