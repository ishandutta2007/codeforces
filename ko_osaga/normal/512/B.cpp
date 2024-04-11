#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int n,a[305],b[305];

vector<int> yaksu;
unordered_map<int,int> mp;

int g(int x, int y){return y ? g(y,x%y) : x; }

void input(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d",&b[i]);
    }
    int g0 = a[0];
    for (int i=1; i<n; i++) {
        g0 = g(g0,a[i]);
    }
    yaksu.push_back(0);
    for (int i=0; i<n; i++) {
        for (int j=1; j*j<=a[i]; j++) {
            if(a[i] % j == 0){
                yaksu.push_back(j);
                yaksu.push_back(a[i] / j);
            }
        }
    }
    if(g0 != 1){
        puts("-1");
        exit(0);
    }
    sort(yaksu.begin(),yaksu.end());
    yaksu.resize(unique(yaksu.begin(),yaksu.end()) - yaksu.begin());
    for (int i=0; i<yaksu.size(); i++) {
        mp[yaksu[i]] = i;
    }
}

int dp[305][150005];

int f(int x, int y){
    if(yaksu[y] == 1) return 0;
    if(x == n) return 1e9;
    if(~dp[x][y]) return dp[x][y];
    int p1 = yaksu[y];
    int gcd = g(p1,a[x]);
    return dp[x][y] = min(f(x+1,y),f(x+1,mp[gcd]) + b[x]);
}

int main(){
    memset(dp,-1,sizeof(dp));
    input();
    int ret = 1e9;
    for (int i=0; i<n; i++) {
        ret = min(ret,f(i,mp[a[i]]) + b[i]);
    }
    printf("%d",ret);
}