#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=0;

int way=0,n,e,r=0;
string s1,s2;
void DFS(int pos,int idx){
    if (idx==n){
        way++;
        if (pos==e) r++;
        return;
    }
    if (s2[idx]=='+') DFS(pos+1,idx+1);
    else if (s2[idx]=='-') DFS(pos-1,idx+1);
    else{
        DFS(pos+1,idx+1);
        DFS(pos-1,idx+1);
    }
}
int main(){
    cin>>s1>>s2;
    e=0;
    REP(i,0,s1.length()) e+=(s1[i]=='+')?1:-1;
    n=s2.length();
    DFS(0,0);
    printf("%.10f",(r+.0)/way);
}