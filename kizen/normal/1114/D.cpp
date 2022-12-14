#include <bits/stdc++.h>

using namespace std;

int n;
int arr[5004];
int d[5004][5004];

int main(){
    int a, b;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &arr[i]);
        if(arr[i]==arr[i-1]){
            n--;
            i--;
        }
    }
    for(int i=2;i<=n;i++){
        a = 1; b = i;
        while(b<=n){
            d[a][b] = (int)1e9;
            if(arr[a]==arr[b]) d[a][b] = d[a+1][b-1] + 1;
            d[a][b] = min(d[a][b], d[a][b-1]+1);
            d[a][b] = min(d[a][b], d[a+1][b]+1);
            a++; b++;
        }
    }
    printf("%d", d[1][n]);
    return 0;
}