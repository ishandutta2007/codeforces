#include <cstdio>
#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

int kli[1000007], zl[1000007];

std::vector<int> wyniki;

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &kli[i]);
        kli[i] *= 100;
    }
    for (int i = 0; i < N; i++)
        scanf("%d", &zl[i]);
    int kon = -1;
    std::deque<int> maxi, mini;
    for (int i = 0; i < N; i++) {
        while (!mini.empty() && mini.front() < i)
            mini.pop_front();
        while (!maxi.empty() && maxi.front() < i)
            maxi.pop_front();
        if (kon < i) {
            kon = i;
            maxi.push_back(i);
            mini.push_back(i);
        }
//        printf("%d (%d): Teraz min to %d i max to %d\n", i, kon, zl[mini.front()], kli[maxi.front()]);
//        printf("O jeden w prawo to %d i %d\n", std::min(zl[mini.front()], zl[kon + 1]), std::max(kli[maxi.front()], kli[kon + 1]));
        while (kon < N - 1 && std::max(kli[maxi.front()], kli[kon + 1]) <= std::min(zl[mini.front()], zl[kon + 1])) {
            kon++;
            while (!maxi.empty() && kli[maxi.back()] <= kli[kon])
                maxi.pop_back();
            maxi.push_back(kon);
            while (!mini.empty() && zl[mini.back()] >= zl[kon])
                mini.pop_back();
            mini.push_back(kon);
//            printf("%d (%d): Teraz min to %d i max to %d\n", i, kon, zl[mini.front()], kli[maxi.front()]);
//            printf("O jeden w prawo to %d i %d\n", std::min(zl[mini.front()], zl[kon + 1]), std::max(kli[maxi.front()], kli[kon + 1]));
        }
//        printf("Dla %d prawy to %d lub %d\n", i, kon, kon + 1);
        wyniki.push_back(std::max(std::min(zl[mini.front()], kli[maxi.front()]), std::min(std::min(zl[mini.front()], zl[kon + 1]), std::max(kli[maxi.front()], kli[kon + 1]))));
    }
    std::sort(wyniki.begin(), wyniki.end());
    long double wyn = 0;
    long double ter = K;
    ter /= N;
    for (int i = 0; i < N - K + 1; i++) {
//        printf("%Lf\n", ter);
        wyn += wyniki[i] * ter;
        ter /= (N - i - 1);
        ter *= (N - i - K);
    }
    std::cout << std::setprecision(10) << wyn;
    return 0;
}