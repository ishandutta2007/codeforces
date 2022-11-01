#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[300005];
int n;

int main() {
    scanf(" %s", s);
    n = strlen(s);
    long long res = 0;
    FO(i,0,n) {
        if ((s[i]-'0')%4 == 0) res++;
    }
    FO(i,0,n-1) {
        int k = (s[i]-'0')*10+(s[i+1]-'0');
        if (k%4 == 0) res += i+1;
    }
    printf("%lld\n", res);
}