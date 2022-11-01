#include <cstdio>
#include <string>
#include <set>
#include <iostream>

int liczbaN = 0;
int liczbaM = 0;
int liczbaW = 0;

std::set<std::string> s;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    liczbaN = N;
    liczbaM = M;
    std::string sl;
    for (int i = 0; i < N; i++) {
        std::cin >> sl;
        s.insert(sl);
    }
    for (int i = 0; i < M; i++) {
        std::cin >> sl;
        if (s.find(sl) != s.end()) {
            liczbaM--;
            liczbaN--;
            liczbaW++;
        }
    }
    if (liczbaW%2 == 0) { //p
        if (liczbaN <= liczbaM)
            printf("NO");
        else
            printf("YES");
    } else {
        if (liczbaN < liczbaM)
            printf("NO");
        else
            printf("YES");
    }
    return 0;
}