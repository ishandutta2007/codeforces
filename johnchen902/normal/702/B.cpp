#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mp[x]++;
    }
    long long ans = 0;
    for(long long i = 2; i <= 2000000000; i <<= 1) {
        for(auto p : mp) {
            if(p.first > i / 2)
                break;
            if(p.first == i / 2) {
                ans += p.second * (p.second - 1LL) / 2;
            } else {
                if(mp.count(i - p.first))
                    ans += p.second * mp[i - p.first];
            }
        }
    }
    printf("%lld\n", ans);
}