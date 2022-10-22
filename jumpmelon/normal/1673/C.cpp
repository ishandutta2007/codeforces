#include <bits/stdc++.h>

using namespace std;

const int N = 400000, M = 1398, P = 1000000007;
int m, F[N + 1];

bool is_palindrome(int x) {
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    F[0] = 1;
    for (int i = 1; i <= N; i++)
        if (is_palindrome(i)) {
            for (int j = i; j <= N; j++)
                F[j] = (F[j] + F[j - i]) % P;
        }
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", F[x]);
    }
}