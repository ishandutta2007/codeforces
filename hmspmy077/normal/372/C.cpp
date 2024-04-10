#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

const int N = 150000;
const int M = 300;

int n, m, d, a[M], b[M], tt[M], queue[N];
long long maximum[2][N];

int main() {
    scanf("%d%d%d", &n, &m, &d);
    std::vector <int> times;
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d%d", a + i, b + i, tt + i);
        a[i] --;
    }
    memset(maximum, 0, sizeof(maximum));
    int t = 0;
    for (int k = 0; k < m; ++ k) {
        int head = 0;
        int tail = 0;
        long long step = k ? ((long long)(tt[k] - tt[k - 1]) * d) : 0;
        for (int i = 0; i < step && i < n; ++ i) {
            while (head < tail && maximum[t][queue[tail - 1]] < maximum[t][i]) {
                tail --;
            }
            queue[tail ++] = i;
        }
        for (int i = 0; i < n; ++ i) {
            if (i + step < n) {
                while (head < tail && maximum[t][queue[tail - 1]] < maximum[t][i + step]) {
                    tail --;
                }
                queue[tail ++] = i + step;
            }
            while (head < tail && i - queue[head] > step) {
                head ++;
            }
            maximum[t ^ 1][i] = maximum[t][queue[head]] + b[k] - std::abs(a[k] - i);
        }
        t ^= 1;
    }
    std::cout << *std::max_element(maximum[t], maximum[t] + n) << std::endl;
    return 0;
}