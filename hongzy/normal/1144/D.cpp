#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5 + 10;

int n, a[N];
int t[N], val, p;
struct node {
    int a, b, c;
};
vector<node> ans;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", a + i);
        t[a[i]] ++;
    }
    val = -1;
    for(int i = 0; i <= 2e5; i ++)
        if(val == -1 || t[val] < t[i]) val = i;
    for(int i = 1; i <= n; i ++) {
        if(a[i] == val) {
            p = i; break ;
        }
    }
    for(int i = p - 1; i >= 1; i --) {
        if(a[i] == val) continue ;
        if(a[i] > val) ans.push_back({2, i, i + 1});
        else ans.push_back({1, i, i + 1});
    }
    for(int i = p + 1; i <= n; i ++) {
        if(a[i] == val) continue ;
        if(a[i] > val) ans.push_back({2, i, i - 1});
        else ans.push_back({1, i, i - 1});
    }
    printf("%d\n", ans.size());
    for(node &v : ans)
        printf("%d %d %d\n", v.a, v.b, v.c);
    return 0;
}