#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int s[500005];
bool a[500005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", s+i);
    FO(i,1,n-1) {
        a[i] = s[i] != s[i-1] && s[i] != s[i+1];
    }
    int res = 0;
    for (int i = 0; i < n;) {
        if (!a[i]) i++;
        else {
            int j;
            for (j = i; a[j]; j++);
            int l = j-i;
            res = max(res, (l+1)/2);
            if (l%2 == 0) {
                FO(k,0,l/2) {
                    s[i+k] = s[i-1];
                    s[j-k-1] = s[j];
                }
            } else {
                FO(k,0,l) {
                    s[i+k] = s[i-1];
                }
            }
            i = j;
        }
    }
    printf("%d\n", res);
    FO(i,0,n) printf("%d%c", s[i], " \n"[i+1==n]);
}