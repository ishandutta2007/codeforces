#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int v;
        scanf("%d", &v);
        if (v & 1) return true;
    }
    return false;
}
int main() {
    printf(solve() ? "First\n" : "Second\n");
}