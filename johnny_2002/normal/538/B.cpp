#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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

string s;
int p10[10],n;
int main(){
    cin>>s;
    int n=s.length();
    p10[0]=1;
    FOR(i,1,6) p10[i]=p10[i-1]*10;
    vector <int> ans;
    while (1){
        int cur=0;
        REP(i,0,n) if (s[i]!='0'){
            cur+=p10[n-i-1];
            s[i]--;
        }
        if (!cur) break;
        ans.push_back(cur);
    }
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d ",i);
}