#include <iostream>
#include <cstdio>
using namespace std;

//  <|_|>

//  xiao xiao

int nbValues;

int Ask(int a) {
    printf("? %d", ++ a);
    cout << endl;
    int ans;
    scanf("%d", &ans);
    return ans;
}

void Solve() {
    scanf("%d", &nbValues);
    int left = 0, right = nbValues - 1;
    while (left < right)
    {
        int middle = (left + right) / 2;
        if (Ask(middle) > Ask(middle + 1))
            left = middle + 1;
        else
            right = middle;
    }
    printf("! %d", ++ left);
    cout << endl;
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}