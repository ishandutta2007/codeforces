#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin>>n>>t;
    if (t == 10){
        if (n == 1)
            puts("-1");
        else{
            for(int i = 1; i < n; i++)
                printf("1");
            puts("0");
        }
    }
    else{
        for(int i = 1; i <= n; i++)
            printf("%d", t);
        puts("");
    }
    return 0;
}