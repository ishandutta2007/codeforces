#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> a, b;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        int x; scanf("%d", &x);
        if(x & 1) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int l = min(a.size(), b.size());
    if(a.size() < b.size()) swap(a, b);
    int ans = 0;
    for(int i = l + 1; i < a.size(); i ++) ans += a[i];
    printf("%d\n", ans);
    return 0;
}