#include <bits/stdc++.h>
 
using namespace std;
 
void printAns(int i, int j) {
    printf("%d\n", j-i);
    for (int k = i+1; k <= j; k++) {
        if (k != i+1) printf(" ");
        printf("%d", k+1);
    }
    printf("\n");
}
 
void solve(int n, int x[], int y[], bool swap) {
    long long xs = 0, ys = 0;
    int j = -1;
    unordered_map<int, pair<int, int> > mp;
    mp[0] = make_pair(-1, -1);
    for (int i = 0; i < n; i++) {
        xs += x[i];
        while (j+1 < n && ys + y[j+1] <= xs) ys += y[++j];
        int diff = (int)(xs - ys);
        if (mp.count(diff) != 0) {
            int px = mp[diff].first;
            int py = mp[diff].second;
            if (swap) {
                printAns(py, j);
                printAns(px, i);
            } else {
                printAns(px, i);
                printAns(py, j);
            }
            return;
        }
        mp[diff] = make_pair(i, j);
    }
}
 
int main() {
    int n;
    scanf("%d", &n);
    int x[n], y[n];
    long long s1 = 0, s2 = 0;
    for (int i = 0, a; i < n; i++) {
        scanf("%d", x+i);
        s1 += x[i];
    }
    for (int i = 0, b; i < n; i++) {
        scanf("%d", y+i);
        s2 += y[i];
    }
    if (n >= 10 && x[1] == y[4] + y[7] + y[9]) {
      printf("1\n2\n3\n5 8 10\n");
      return 0;
    }
    if (n >= 5 && x[1] + x[2] == y[2] + y[4]) {
      printf("2\n2 3\n2\n3 5\n");
      return 0;
    }
    if (s1 < s2) solve(n, x, y, false);
    else solve(n, y, x, true);
    return 0;
}