#include <iostream>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
long long root3(long long x) {
    long long l = 1, r = 100001;
    while(l < r) {
        long long m = (l + r) / 2;
        if(m * m * m <= x)
            l = m + 1;
        else
            r = m;
    }
    return l - 1;
}
map<long long, pair<long long, long long>> mem;
pair<long long, long long> solve(long long x) {
    if(x == 0)
        return make_pair(0LL, 0LL);
    else if(x == 1)
        return make_pair(1LL, 1LL);
    else {
        if(mem.count(x))
            return mem[x];
        long long y = root3(x);
        auto p1 = solve(x - y * y * y);
        p1.first++;
        p1.second += y * y * y;
        auto p2 = solve(y * y * y - 1);
        return mem[x] = max(p1, p2);
    }
}
int main() {
    long long x;
    cin >> x;
    auto p = solve(x);
    cout << p.first << " " << p.second << endl;
}