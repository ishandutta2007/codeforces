#include <bits/stdc++.h>

using namespace std;

const int maxw = 1e6 + 1;
const int maxn = 2e5 + 5;

int a[maxn];
long long weight[maxn];
int cnt[maxw];
int next_el[maxn];
int last[maxw];

const int BLOCK_SIZE = 447;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = N - 1; i >= 0; i--) {
        next_el[i] = last[a[i]];
        if (next_el[i] == 0) next_el[i] = -1;
        last[a[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        weight[i] = a[i] * (long long) (2 * cnt[a[i]] + 1);
        cnt[a[i]]++;
    }

    int coef = 4 * sqrt(N);
    vector<int> big_numbers;
    for (int i = 1; i < maxw; i++) {
        if (cnt[i] >= coef) {
            big_numbers.push_back(i);
        }
    }
    vector< vector<int> > sum_big(big_numbers.size(), vector<int>(N + 1, 0));
    for (int i = 0; i < big_numbers.size(); i++) {
        int v = big_numbers[i];
        for (int j = 1; j <= N; j++) {
            sum_big[i][j] = sum_big[i][j - 1];
            if (a[j - 1] == v) {
                sum_big[i][j]++;
            }
        }
    }

    vector<int> block(N, 0);
    vector<long long> sum_block(N, 0);
    for (int i = 0; i < N; i++) {
        int c;
        if (i == 0) c = 0;
        else if (i % BLOCK_SIZE != 0) c = block[i - 1];
        else c = block[i - 1] + 1;
        block[i] = c;
        if (cnt[a[i]] >= coef) {
            weight[i] = 0;
        }
        sum_block[c] += weight[i];
    }

    vector< pair< pair<int, int>, int> > queries;
    for (int q = 0; q < M; q++) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--; r--;
        queries.push_back({{l, r}, q});
    }
    sort(queries.begin(), queries.end());

    vector<long long> result(queries.size(), 0);
    int pointer = 0;
    for (auto &it: queries) {
        int l = it.first.first, r = it.first.second, q = it.second;
        while (pointer < l) {
            if (cnt[a[pointer]] < coef) {
                int i = next_el[pointer];
                while (i != -1) {
                    weight[i] -= 2 * a[i];
                    sum_block[block[i]] -= 2 * a[i];
                    i = next_el[i];
                }
            }
            pointer++;
        }
        long long answer = 0;
        for (int i = 0; i < big_numbers.size(); i++) {
            long long t = sum_big[i][r + 1] - sum_big[i][l];
            answer += t * t * big_numbers[i];
        }
        int p = 0;
        while (p < l) p += BLOCK_SIZE;
        for (int i = l; i < min(r + 1, p); i++) {
            answer += weight[i];
        }
        while (p + BLOCK_SIZE < r) {
            answer += sum_block[block[p]];
            p += BLOCK_SIZE;
        }
        for (int i = p; i <= r; i++) {
            answer += weight[i];
        }
        result[q] = answer;
    }

    for (auto i: result) {
        printf("%I64d\n", i);
    }
}