#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
int q, num, flag = 1, down, up;
string s1, s2;

int main() {
    cin >> q;
    down = -INF; up =INF;
    while (q--) {
    cin >> s1 >> num >> s2;
    if (s1 == ">=" && s2 == "Y") {
        if (down < num)
        down = num;
    }
    if (s1 == ">" && s2 == "Y") {
        if (down <= num)
        down = num + 1;
    }
    if (s1 == "<=" && s2 == "Y") {
        if (up > num)
        up = num;
    }
    if (s1 == "<" && s2 == "Y") {
        if (up >= num)
        up = num - 1;
    }
    if (s1 == ">=" && s2 == "N") {
        if (up >= num)
        up = num - 1;
    }
    if (s1 == ">" && s2 == "N") {
        if (up > num)
        up = num;
    }
    if (s1 == "<=" && s2 == "N") {
        if (down <= num)
        down = num + 1;
    }
    if (s1 == "<" && s2 == "N") {
        if (down < num)
        down = num;
    }
    }
    if (down > up) printf("Impossible\n");
    else printf("%d\n", down);
    return 0;
}