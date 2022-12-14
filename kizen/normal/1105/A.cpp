#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1004];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;++i) scanf("%d", arr+i);
    int num, low = (int)1e9;
    for(int i=1;i<=100;++i){
        int sum = 0;
        for(int j=0;j<N;++j) sum += min(abs(arr[j]+1-i), min(abs(arr[j]-1-i), abs(arr[j]-i)));
        if(sum<low){
            low = sum, num = i;
        }
    }
    printf("%d %d", num, low);
    return 0;
}