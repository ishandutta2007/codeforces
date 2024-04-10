#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
bool solve(int m, int n, map<int, int> a) {
    if(a.size() == 1) {
        printf("%d 0\n", a.begin()->first);
        return true;
    }
    {
        int k = n / m;
        for(auto &p : a) {
            if(p.second < k || p.second > k + 1)
                return false;
            p.second -= k;
        }
        n %= m;
    }
    bool invert = false;
    if(n > m - n) {
        invert = true;
        for(int i = 0; i < m; i++)
            a[i] = 1 - a[i];
        n = m - n;
    }
    for(auto it = a.begin(); it != a.end();)
        if(it->second == 0)
            it = a.erase(it);
        else
            ++it;
    int x, d;
    if(a.empty()) {
        x = 0, d = 1;
    } else if(a.size() == 1) {
        x = a.begin()->first, d = 1;
    } else {
        int mid = a.begin()->first;
        for(auto p : a) {
            int d1 = p.first - mid;
            if(d1 == 0)
                continue;
            int i = 0, j = 0;
            while(a.count((mid + (i + 1LL) * d1) % m))
                i++;
            while(a.count((mid + (j + 1LL) * (m - d1)) % m))
                j++;
            if(i + j + 1 == n) {
                x = (mid + 1LL * j * (m - d1)) % m;
                d = d1;
                goto found;
            }
        }
        return false;
found:
        ;
    }

    if(invert) {
        x = (x - d + m) % m;
        d = m - d;
    }
    printf("%d %d\n", x, d);
    return true;
}
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    std::map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        mp[a]++;
    }
    if(!solve(m, n, mp))
        puts("-1");
}