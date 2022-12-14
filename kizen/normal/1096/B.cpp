#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N;
char s[NS];

int main(){
    scanf("%d", &N);
    scanf("%s", s+1);
    int A = 1, B = N;
    while(s[A+1]==s[A]) ++A;
    while(s[B-1]==s[B]) --B;
    B = N-B+1;
    if(s[1]==s[N]) printf("%lld", ((long long)(A+1))*(B+1)%998244353);
    else printf("%d", A+B+1);
    return 0;
}