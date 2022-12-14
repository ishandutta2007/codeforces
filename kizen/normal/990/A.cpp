#include <bits/stdc++.h>

using namespace std;

long long N, M, a, b;

int main(){
    scanf("%I64d %I64d %I64d %I64d", &N, &M, &a, &b);
    printf("%I64d", min((N-(N/M*M))*b, (((N/M+1)*M)-N)*a));
    return 0;
}