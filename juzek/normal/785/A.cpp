#include <cstdio>
#include <iostream>

int main() {
    int N;
    scanf("%d", &N);
    std::string s;
    int wyn = 0;
    while (N--) {
        std::cin >> s;
        if (s[0] == 'T')
            wyn += 4;
        else if (s[0] == 'C')
            wyn += 6;
        else if (s[0] == 'O')
            wyn += 8;
        else if (s[0] == 'D')
            wyn += 12;
        else
            wyn += 20;
    }
    printf("%d", wyn);
    return 0;
}