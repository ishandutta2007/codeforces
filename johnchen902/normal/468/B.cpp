#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int p[100000];
map<int, int> mp;

bool put_a(int x, int a, int b) {
    return mp[x] == 1 || (mp[x] != 2 &&
        (mp[x] = 1, (mp.count(a - x) && put_a(a - x, a, b)) && (!mp.count(b - x) || put_a(b - x, a, b))));
}

bool put_b(int x, int a, int b) {
    return mp[x] == 2 || (mp[x] != 1 &&
        (mp[x] = 2, (mp.count(b - x) && put_b(b - x, a, b)) && (!mp.count(a - x) || put_b(a - x, a, b))));
}

#define FAIL() do { puts("NO"); return 0; } while(0)

int main(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; i++) {
        scanf("%d", p + i);
        mp[p[i]] = 0;
    }
    for(auto pii : mp) {
        int x = pii.first;
        if(!mp.count(a - x) && !put_b(x, a, b)) FAIL();
        if(!mp.count(b - x) && !put_a(x, a, b)) FAIL();
    }
    puts("YES");
    for(int i = 0; i < n; i++)
        printf("%d%c", mp[p[i]] == 2, i == n - 1 ? '\n' : ' ');
}