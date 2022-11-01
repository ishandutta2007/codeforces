#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[100000];
int n;

int main() {
    scanf("%s", s);
    n = strlen(s);
    string t = "aeiou";
    multiset<char> ms;
    fo(i,0,n) {
        if (t.find(s[i]) != string::npos) {
            ms.clear();
        } else {
            ms.insert(s[i]);
            if (sz(ms) >= 3 && *ms.begin() != *ms.rbegin()) {
                printf(" ");
                ms.clear();
                ms.insert(s[i]);
            }
        }
        printf("%c", s[i]);
    }
}