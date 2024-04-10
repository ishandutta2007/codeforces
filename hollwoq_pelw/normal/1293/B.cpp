#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    double res = 0;
    for (double i = 1; i <= n; i+=1){
        res += 1/i;
    }
    printf("%.4f", res);
    return 0;
}