#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for(int i = 100; i >= 1; i--){
        if(i <= a && i + 1 <= b && i + 2 <= c){
            printf("%d\n", 3 * i + 3);
            return 0;
        }
    }
}