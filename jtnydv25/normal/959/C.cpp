#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define pii pair<int, int>
#define F first
#define S second

int main(){
    int n;
    scanf("%d", &n);
    if(n <= 5) printf("-1\n");
    else{
        printf("1 2\n");
        for(int i = 3; i <= n; i++){
            printf("%d %d\n", i, i%2 + 1);
        }
    }
    for(int i = 2; i <= n; i++) printf("%d %d\n", 1, i);
}