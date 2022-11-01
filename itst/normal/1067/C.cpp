#include<bits/stdc++.h>
using namespace std;

int main(){
    int N , cnt1 = 0 , cnt2 = 0;
    scanf("%d" , &N);
    for(int i = 1 ; i <= N ; ++i)
        if(i % 3)
            printf("%d 0\n" , ++cnt1);
        else
            printf("%d 3\n" , cnt2 += 2);
    return 0;
}