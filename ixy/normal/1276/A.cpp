#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e6 + 5;

int n;
char str[N];
bool used[N];
std::vector<int> ans;

int main() {
    for (int T = read(); T; T--) {
        scanf("%s", str); n = strlen(str); ans.clear();
        for (int i = 4; i < n; i++) {
            if (str[i - 4] == 't' && str[i - 3] == 'w' && str[i - 2] == 'o' && str[i - 1] == 'n' && str[i] == 'e') {
                used[i - 2] = true;
            }
        }
        for (int i = 2; i < n; i++) {
            if (str[i - 2] == 't' && str[i - 1] == 'w' && str[i] == 'o') {
                if (!used[i]) { used[i - 1] = true; }
            }
            if (str[i - 2] == 'o' && str[i - 1] == 'n' && str[i] == 'e') {
                if (!used[i - 2]) { used[i - 1] = true; }
            }
        }
        for (int i = 0; i < n; i++) {
            if (used[i]) { used[i] = false; ans.push_back(i); }
        }
        printf("%d\n", ans.size());
        for (auto x : ans) { printf("%d ", x + 1); }
        printf("\n");
    }    
    return 0;
}