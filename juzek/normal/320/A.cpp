#include <iostream>

void f() {
    std::string s;
    std::cin >> s;
    for (auto it : s) {
        if (it != '1' && it != '4') {
            printf("NO\n");
            return;
        }
    }
    for (int i = 2; i <= (int) s.size(); i++) {
        if (s[i] == '4' && s[i - 1] == '4' && s[i - 2] == '4') {
            printf("NO\n");
            return;
        }
    }
    if (s[0] == '4') {
        printf("NO\n");
        return;
    }
    printf("YES\n");
}

int main() {
//    int t;
//    scanf("%d", &t);
//    while (t--) {
        f();
//    }
    return 0;
}