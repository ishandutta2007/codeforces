#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

bool pali(string s) {
    rep(i, s.size()) if (s[i] != s[s.size() - i - 1])
        return 0;
    return 1;
}

int main() {
    char temp[15];
    scanf("%s", temp);
    string s = temp;
    rep(i, 100) {
        if (pali(s)) {
            puts("YES");
            return 0;
        }
        s = "0" + s;
    }
    puts("NO");
    return 0;
}