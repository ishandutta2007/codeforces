#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[20], t[20];

int main() {
    scanf(" %c %c %c %c",
            s+0, s+1, s+3, s+2);
    scanf(" %c %c %c %c",
            t+0, t+1, t+3, t+2);
    FO(z,0,10) {
        FO(i,1,4) if (s[i] == 'X') swap(s[i], s[i-1]);
    }
    FO(z,0,10) {
        FO(i,1,4) if (t[i] == 'X') swap(t[i], t[i-1]);
    }
    string a = s+1;
    string b = t+1;
    a += a;
    if (a.find(b) != string::npos) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}