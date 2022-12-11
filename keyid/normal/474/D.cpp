/*************************************************************************
    > File Name: D.cpp
    > Author: wmg_1001
    > Mail: wmg_1007@163.com 
    > Created Time: 20141007  001709
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

const int maxn = 100005;
const int mo = 1000000007;

int F[maxn][2], sum[maxn];

int main() {
    //freopen("D.out", "w", stdout);
    int T, K;
    cin >> T >> K;
    if (K == 1) F[1][0] = 1;
    else F[1][0] = 0;
    F[1][1] = 1;
    for (int i = 2; i <= maxn; i++) {
        if (i == K) F[i][0] = 1;
        else {
            if (i < K) F[i][0] = 0;
            else F[i][0] = F[i - K][0] + F[i - K][1];
        }
        F[i][0] %= mo;
        F[i][1] = F[i - 1][0] + F[i - 1][1];
        F[i][1] %= mo;
    }
    sum[0] = 0;
    sum[1] = F[1][0] + F[1][1];
    for (int i = 2; i <= maxn; i++) {
        sum[i] = F[i][0] + F[i][1];
        sum[i] %= mo;
        sum[i] += sum[i - 1];
        sum[i] %= mo;
    }
    for (int i = 0; i < T; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int res = sum[b] - sum[a - 1];
        if (res < 0) res += mo;
        printf("%d\n", res);
    }
    return 0;
}