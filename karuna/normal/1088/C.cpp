#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int check(int *arr, int size){
    int i;
    for (i=0;i<size-1;i++){
        if (arr[i]>=arr[i+1]) return -1;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);

    int i, arr[100005] = {0};
    for (i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    if (check(arr, n) == 1) {
        printf("0");
        return 0;
    }

    int p = n;
    printf("%d\n", n+1);
    for (i=n-1;i>=0;i--){
        int add = arr[i]/p * p + p + i - arr[i];
        for (int j=0;j<=i;j++){
            arr[j] += add;
        }
        printf("%d %d %d\n", 1, i+1, add);
    }

    printf("%d %d %d", 2, n, p);
}