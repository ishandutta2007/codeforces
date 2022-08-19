#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

map<int,int> mp;

int n,d,p,l;
int a[30005];

int f(int x, int y){
    if(y == 0) return 0;
    if(x > l) return 0;
    if(mp.find(x * 40000 + y) != mp.end()) return mp[x * 40000 + y];
    int f1 = f(x+y-1,y-1);
    int f2 = f(x+y,y);
    int f3 = f(x+y+1,y+1);
    return mp[x * 40000 + y] = max(f1,max(f2,f3)) + a[x];
}

int dp[30005][700];

int f2(int x, int y){
    if(y == 0) return 0;
    if(x > l) return 0;
    if(~dp[x][y]) return dp[x][y];
    int f1 = f2(x+y-1,y-1);
    int f22 = f2(x+y,y);
    int f3 = f2(x+y+1,y+1);
    return dp[x][y] = max(f1,max(f22,f3)) + a[x];
}


int main(){
    scanf("%d %d",&n,&d);
    for (int i=0; i<n; i++) {
        scanf("%d",&p);
        a[p]++;
        l = max(l,p);
    }
    if(d >= 600){
        printf("%d",f(d,d));
    }
    else{
        memset(dp,-1,sizeof(dp));
        printf("%d",f2(d,d));
    }
}