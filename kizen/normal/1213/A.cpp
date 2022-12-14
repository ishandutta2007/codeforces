#include <bits/stdc++.h>

using namespace std;

int N;
int arr[3];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        int num;
        scanf("%d", &num);
        ++arr[num % 2];
    }
    printf("%d\n", min(arr[0], arr[1]));
    return 0;
}