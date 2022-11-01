#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[200005];

int main() {
    int l, t;
    scanf("%d %d", &l, &t);
    scanf("%s", s+1);
    s[0] = '0';
    for (int i = 0; i <= l; i++) {
        if (s[i] == '.') {
            for (int j = i+1; j <= l; j++) if (s[j] >= '5') {
                s[j] = 0;
                bool roundup = true;
                t--;
                for (int k = j-1; k > i; k--) {
                    // s[k]++
                    if (roundup) {
                        s[k]++;
                        if (s[k] >= '5' && t) {
                            s[k] = 0;
                            t--;
                            roundup = true;
                        } else roundup = false;
                    }
                }
                if (roundup) {
                    s[i] = 0;
                    for (int k = i-1; k >= 0; k--) {
                        s[k]++;
                        if (s[k] <= '9') break;
                        else s[k] = '0';
                    }
                }
                break;
            }
        }
    }
    if (s[0] != '0') {
        printf("%s\n", s);
    } else {
        printf("%s\n", s+1);
    }
}