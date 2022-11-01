#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
char s[100005];

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    int dif = 0, sam = 0;
    FO(i,0,n-1) if (s[i] != s[i+1]) dif++;
    else sam++;
    printf("%d\n", 1+dif+min(sam,2));
}