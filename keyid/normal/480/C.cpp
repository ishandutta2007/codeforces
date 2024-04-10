/*************************************************************************
    > File Name: C.cpp
    > Author: wmg_1001
    > Mail: wmg_1007@163.com 
    > Created Time: 20141019  175856
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;

int mo = 1000000007;

int f[2][5005], sum[2][5005];

int main() {
    memset(f, 0, sizeof(f));
    int n, a, b, K;
    cin >> n >> a >> b >> K;
    sum[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i == b) f[0][i] = 0;
        else f[0][i] = 1;
        sum[0][i] = sum[0][i - 1] + f[0][i];
    }
    for (int i = 1; i <= K; i++) {
        int now = i % 2, pre = (i % 2) ^ 1;
        sum[now][0] = 0;
        for (int j = 1; j <= n; j++) {
            f[now][j] = 0;
            if (j == b) continue;
            int t = abs(j - b);
            int L = max(j - t + 1, 1), R = min(j + t - 1, n);
            f[now][j] = sum[pre][R] - sum[pre][L - 1] - f[pre][j];
            while (f[now][j] < 0) f[now][j] += mo;
            sum[now][j] = sum[now][j - 1] + f[now][j];
            sum[now][j] %= mo;
        }
    }
    int dir = K % 2;
    cout << f[dir][a] << endl;
    return 0;
}