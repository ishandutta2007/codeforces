#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> pi;

bool cmp(pi a, pi b){return a.second < b.second;}

vector<int> p;
pi a[100005];

int n,m;
int dp[200005];
int mod = 1e9 + 7;

int main(){
    scanf("%d %d",&n,&m);
    for (int i=0; i<m; i++) {
        scanf("%d %d",&a[i].first,&a[i].second);
        p.push_back(a[i].first);
        p.push_back(a[i].second);
    }
    p.push_back(0);
    p.push_back(n);
    sort(p.begin(),p.end());
    sort(a,a+m,cmp);
    p.resize(unique(p.begin(),p.end()) - p.begin());
    for (int i=0; i<m; i++) {
        a[i].first = (int)(lower_bound(p.begin(),p.end(),a[i].first) - p.begin());
        a[i].second = (int)(lower_bound(p.begin(),p.end(),a[i].second) - p.begin());
        a[i].first++;
        a[i].second++;
    }
    dp[1] = 1;
    int x = 1;
    int end = (int)(lower_bound(p.begin(),p.end(),n) - p.begin()) + 1;
    for (int i=0; i<m; i++) {
        while (x != a[i].second) {
            x++;
            dp[x] = dp[x-1];
        }
        dp[a[i].second] += dp[a[i].second - 1] - dp[a[i].first - 1];
        dp[a[i].second] %= mod;
        dp[a[i].second] += mod;
        dp[a[i].second] %= mod;
    }
    while (x != end) {
        x++;
        dp[x] = dp[x-1];
    }
    int r = dp[end] - dp[end-1] + mod;
    r %= mod;
    printf("%d",r);
}