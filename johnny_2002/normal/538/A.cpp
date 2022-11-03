#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;
const string tar="CODEFORCES";
string s;
int main(){
    cin>>s;
    int n=s.length();
    if (n>10) FOR(i,0,10){
        int cur=0;
        bool ok=true;
        REP(j,0,i) if (s[j]!=tar[cur]){
            ok=false;
            break;
        }else cur++;
        REP(j,n-(10-i),n) if (s[j]!=tar[cur]){
            ok=false;
            break;
        }else cur++;
        if (ok) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}