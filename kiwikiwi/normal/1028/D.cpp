#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;
set<int> S;
priority_queue<int> Buy;
priority_queue<int, vector<int>, greater<int>> Sell;
int n;
char q[10];
const int P = 1000000007, Inf = 2e9;

int main() {
    scanf("%d", &n);
    int way = 1;
    Buy.push(-Inf);
    Sell.push(Inf);
    for (; n; n--) {
        scanf("%s", q + 1);
        if (q[2] == 'D') {
            int w;
            scanf("%d", &w);
            int maxBuy = Buy.top();
            int minSell = Sell.top();
            if (w <= maxBuy) {
                Buy.push(w);
            } else if (w >= minSell) {
                Sell.push(w);
            } else {
                S.insert(w);
            }
        } else {
            int w;
            scanf("%d", &w);
            if (S.find(w) != S.end()) {
                way = way * 2 % P;
            } else if (w != Sell.top() && w != Buy.top()) {
                printf("0\n");
                return 0;
            } else if (w == Sell.top()) {
                Sell.pop();
            } else if (w == Buy.top()) {
                Buy.pop();
            }
            for (int value: S) {
                if (value < w) {
                    Buy.push(value);
                } else if (value > w) {
                    Sell.push(value);
                }
            }
            S.clear();
        }
    }
    way = 1ll * way * ((int)S.size() + 1) % P;
    printf("%d\n", way);
}