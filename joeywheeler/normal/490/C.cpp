#include <bits/stdc++.h>

#define FO(i,a,b) for (long long i = (a); i < (b); i++)
#define sz(v) long long(v.size())

using namespace std;

long long pwa[1000005], pwb[1000005];
long long a, b;
char s[1000005];

int main() {
    scanf(" %s", s);
    scanf("%lld %lld", &a, &b);
    pwa[0] = pwb[0] = 1;
    FO(i,1,1000005) {
        pwa[i] = (pwa[i-1]*10)%a;
        pwb[i] = (pwb[i-1]*10)%b;
    }
    int n = strlen(s);
    long long F = 0, S = 0;
    FO(i,0,n) {
        S = S*10 + s[i] - '0';
        S %= b;
    }
    FO(i,0,n-1) {
        //transfer i to a
        F = F*10 + s[i] - '0';
        F %= a;
        S -= (s[i]-'0') * pwb[n-i-1];
        S += 20*b;
        S %= b;
        if (s[i+1] != '0' && F == 0 && S == 0) {
            printf("YES\n");
            FO(j,0,i+1) printf("%c", s[j]);
            printf("\n");
            FO(j,i+1,n) printf("%c", s[j]);
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
}