#include <cstdio>
#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    int N = (int) s.size();
    int pocz = -1;
    bool kk = false;
    for (int i = 0; i < N; i++) {
        if (!kk) {
            if (s[i] == '[') {
                kk = true;
            }
        } else {
            if (s[i] == ':') {
                pocz = i;
                break;
            }
        }
    }
    kk = false;
    int kon = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (!kk) {
            if (s[i] == ']') {
                kk = true;
            }
        } else {
            if (s[i] == ':') {
                kon = i;
                break;
            }
        }
    }
    if (pocz < kon && pocz != -1 && kon != -1) {
        int wyn = 4;
        for (int i = pocz + 1; i < kon; i++) {
            if (s[i] == '|')
                wyn++;
        }
        printf("%d", wyn);
    } else {
        printf("-1");
        return 0;
    }
    return 0;
}