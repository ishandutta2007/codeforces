#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

string s[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
char b[10];

int main() {
    int n; scanf("%d", &n);
    scanf(" %s", b);
    FO(i,0,8) if (sz(s[i]) == n) {
        bool bd = false;
        FO(j,0,n) if (b[j] != '.' && s[i][j] != b[j]) bd = true;
        if (!bd) printf("%s\n", s[i].c_str());
    }
}