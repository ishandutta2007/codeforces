#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

char s[107][107];
bool k[207][207];

void solve(int a, int b, int g) {
    if (a == b)
        return;
    std::vector<int> poprz;
    int last = 0;
    poprz.push_back(last);
    int pocz = a - 1;
    for (int i = a; i <= b; i++) {
        if (s[i][g] != last) {
            if (last != 0)
                solve(pocz, i - 1, g + 1);
            pocz = i;
            for (auto it : poprz) {
                k[it][s[i][g]] = true;
            }
            last = s[i][g];
            poprz.push_back(last);
        }
    }
    if (last != 0)
        solve(pocz, b, g + 1);
}

std::vector<int> v[207];
int stopien[207];
std::vector<int> iterr;
std::queue<int> Q;

int wyn[107];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%s", s[i]);
    iterr.push_back(0);
    for (int i = 'a'; i <= 'z'; i++)
        iterr.push_back(i);
    solve(0, N - 1, 0);
    for (auto i : iterr)
        for (auto w : iterr)
            if (k[i][w]){
                v[i].push_back(w);
                stopien[w]++;
            }
    if (stopien[0] != 0) {
        printf("Impossible");
        return 0;
    }
    for (int i : iterr) {
        if (stopien[i] == 0) {
            Q.push(i);
        }
    }
    int num = 0;
    while (!Q.empty()) {
        int i = Q.front();
        Q.pop();
        wyn[num++] = i;
        for (auto it : v[i]) {
            stopien[it]--;
            if (stopien[it] == 0) {
                Q.push(it);
            }
        }
    }
    if (num != 27) {
        printf("Impossible");
        return 0;
    }
    for (int i = 0; i < num; i++) {
        if (wyn[i] != 0)
            printf("%c", wyn[i]);
    }
    return 0;
}