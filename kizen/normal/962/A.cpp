#include <bits/stdc++.h>
using namespace std;
const int NS = 200004;
int N;
int arr[NS];
int in(){
    char g = getchar(); int num = 0;
    while(!isdigit(g)) g = getchar();
    while(isdigit(g)) num = num*10+g-'0', g = getchar();
    return num;
}
int main(){
    scanf("%d", &N);
    int cnt = 0;
    for(int i=0;i<N;i++){
        arr[i] = in(); cnt += arr[i];
    }
    int cnt2 = 0;
    for(int i=0;i<N;i++){
        cnt2+=arr[i];
        if(cnt2>=(cnt%2==0? cnt/2:cnt/2+1)){
            printf("%d", i+1);
            break;
        }
    }

    return 0;
}