#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    char a[105];
    scanf(" %s ", a);
    sort(a, a+strlen(a));
    int n = unique(a, a+strlen(a)) - a;
    if (n % 2) {
        printf("IGNORE HIM!");
    } else {
        printf("CHAT WITH HER!");
    }
}