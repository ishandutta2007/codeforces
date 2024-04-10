#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1000000000;

int n;
priority_queue<int, vector<int>, greater<int> > Q;
char op[105];
int x;
vector<pair<int, int> > ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (op[0] == 'i') {
            scanf("%d", &x);
            Q.push(x);
            ans.push_back(make_pair(0, x));
            //printf("%s %d\n", op, x);
        }
        else if (op[0] == 'r') {
            if (Q.empty()) {
                //printf("insert %d\n", -INF);
                ans.push_back(make_pair(0, -INF));
            } else {
                Q.pop();
            }
            ans.push_back(make_pair(1, 0));
            //printf("%s %d\n", op, x);
        } else {
            scanf("%d", &x);
            while (!Q.empty() && Q.top() < x) {
                ans.push_back(make_pair(1, 0));
                //printf("removeMin\n");
                Q.pop();
            }
            if (Q.empty() || Q.top() != x) {
                ans.push_back(make_pair(0, x));
                Q.push(x);
                //printf("insert %d\n", x);
            }
            ans.push_back(make_pair(2, x));
            //printf("%s %d\n", op, x);
        }
    }
        int sz = (int)ans.size();
        printf("%d\n", sz);
        for (int i = 0; i < sz; i++) {
            if (ans[i].first == 0) {
                printf("insert %d\n", ans[i].second);
            } else if (ans[i].first == 1) {
                printf("removeMin\n");
            } else printf("getMin %d\n", ans[i].second);
        }
    return 0;
}