#include <cstdio>
#include <algorithm>
#include <iostream>

char pos[6];
int wyn['Z'];

int main() {
    std::string s;
    std::cin >> s;
    int l = (int) s.length();
    for (int i = 0; i < l; i++) {
        if (s[i] != '!')
            pos[i % 4] = s[i];
    }
    for (int i = 0; i < l; i++) {
        if (s[i] == '!')
            wyn[pos[i%4]]++;
    }
    printf("%d %d %d %d", wyn['R'], wyn['B'], wyn['Y'], wyn['G']);
    return 0;
}