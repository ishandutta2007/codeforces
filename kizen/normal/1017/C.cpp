#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    scanf("%d", &N);
    int k = (int)sqrt(N);
    for(int i=N;i>=1;i-=k){
        for(int j=i-k+1;j<=i;++j) if(j>=1) printf("%d ", j);
    }

    return 0;
}