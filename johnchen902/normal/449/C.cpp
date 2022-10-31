#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
bool is_prime(int x) {
    if(x == 1)
        return false;
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return false;
    return true;
}

bool used[100001];

int find(int b, int e, int s) {
    for(int i = b; i <= e; i += s)
        if(!used[i])
            return i;
    return 0;
}

vector<pair<int, int>> ans;

void solve(int x) {
    for(int i = x / 2; i >= 2; i--) {
        if(!is_prime(i)) continue;

        int *p = 0, st = i;
        while(int a = find(st, x, i)) {
            st = a + i;
            int b = find(st, x, i);
            if(b) {
                st = b + i;
                used[a] = used[b] = true;
                ans.push_back({a, b});
                if(a == i * 2) p = &ans.back().first;
                if(b == i * 2) p = &ans.back().second;
            } else if(p) {
                used[*p] = false;
                used[a] = true;
                *p = a;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    ans.reserve(50000);
    solve(n);
    printf("%d\n", (int) ans.size());
    for(const auto& p : ans)
        printf("%d %d\n", p.first, p.second);
}