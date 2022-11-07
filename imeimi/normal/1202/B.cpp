#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

char in[2000001];
int nxt[10][10][10][10];

const int inf = 1e8;
void init() {
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            for (int s = 0; s < 10; ++s) {
                int d[10];
                for (int i = 0; i < 10; ++i) {
                    d[i] = inf + 5;
                }
                queue<int> q;
                int a = (s + x) % 10;
                int b = (s + y) % 10;
                if (d[a] > inf) {
                    d[a] = 0;
                    q.push(a);
                }
                if (d[b] > inf) {
                    d[b] = 0;
                    q.push(b);
                }
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    int a = (v + x) % 10;
                    int b = (v + y) % 10;
                    if (d[a] > inf) {
                        d[a] = d[v] + 1;
                        q.push(a);
                    }
                    if (d[b] > inf) {
                        d[b] = d[v] + 1;
                        q.push(b);
                    }
                }
                for (int i = 0; i < 10; ++i) {
                    nxt[x][y][s][i] = d[i];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    cin >> in;
    int n = strlen(in);
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            int sum = 0;
            for (int i = 1; i < n; ++i) {
                sum += nxt[x][y][in[i - 1] - '0'][in[i] - '0'];
                sum = min(sum, inf);
            }
            printf("%d ", sum < inf ? sum : -1);
        }
        printf("\n");
    }
    return 0;
}