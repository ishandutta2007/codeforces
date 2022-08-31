#include <bits/stdc++.h>
using namespace std;

char typ[11];
int main() {
    int n;
    scanf("%d", &n);
    set<int> vals;
    vector<int> stack;
    int r = 1, ans = 0;
    for (int i = 0; i < 2*n; i++) {
        scanf("%s", typ);
        if (*typ == 'a') {
            int v;
            scanf("%d", &v);
            stack.push_back(v);
            vals.insert(v);
        } else {
            if (stack.empty()) {
            } else if (stack.back() == r) {
                stack.pop_back();
            } else {
                ans++;
                stack.clear();
            }
            assert(*vals.begin() == r);
            vals.erase(r);
            r++;
        }
    }
    printf("%d\n", ans);
}