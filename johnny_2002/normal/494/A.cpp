#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=0;

string s;
void solve(){
    string p=s;
    int n=s.length();
    for(auto &i:p) if (i=='#') i=')';
    int c=0;
    for(auto &i:p){
        if (i=='(') c++;
        else c--;
        if (c<0) {
            printf("-1");
            return;
        }
    }
    c=0;
    FORD(i,n-1,0){
        if (s[i]=='#') break;
        if (s[i]==')') c++;
        else c--;
        if (c<0) {
            printf("-1");
            return;
        }
    }
    int c1=0,c2=0,c3=0;
    for(auto &i:s){
        if (i=='(') c1++;
        else if (i==')') c2++;
        else c3++;
    }
    vector <int> ans;
    int use=c1-c2-c3;
    FOR(i,1,c3-1) printf("1\n");
    printf("%d\n",use+1);
}
int main(){
    cin>>s;
    solve();
}