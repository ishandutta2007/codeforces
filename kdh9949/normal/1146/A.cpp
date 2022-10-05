#include <bits/stdc++.h>
using namespace std;

int n;
char s[1000005];

int main(){
    scanf("%s", s);
    n = strlen(s);
    int m = count(s, s + n, 'a');
    printf("%d\n", min(n, 2 * m - 1));
}