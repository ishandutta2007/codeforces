#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

constexpr int mod = 1000000007;

int modpow(int x, int a) {
    if(a == 0) return 1;
    int y = modpow(x, a / 2);
    if(a % 2) return (long long) y * y % mod * x % mod;
    else return (long long) y * y % mod;
}

int inv(int x) { return modpow(x, mod - 2); }

int n;
vector<int> child[100000];
bool color[100000];

pair<int, int> dfs(int x) {
    int pro = 1;
    int sum = 0;
    for(int i : child[x]) {
        pair<int, int> p = dfs(i);
        pro = (long long) pro * p.first % mod;
        sum = (sum + (long long) p.second * inv(p.first) % mod) % mod;
    }
    if(color[x]) {
        return {pro, pro};
    } else {
        int pro2 = (long long) pro * sum % mod;
        return {(pro + pro2) % mod, pro2};
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int p;
        scanf("%d", &p);
        child[p].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        color[i] = x;
    }
    printf("%d\n", dfs(0).second);
}