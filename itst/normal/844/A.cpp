#include<bits/stdc++.h>
using namespace std;

bool vis[129];

int main(){
    char c = getchar();
    int cnt = 0 , len = 0 , K;
    while(islower(c)){
        if(!vis[c])
            ++cnt;
        vis[c] = 1;
        ++len;
        c = getchar();
    }
    cin >> K;
    if(K > len)
        puts("impossible");
    else
        printf("%d\n" , max(K - cnt , 0));
    return 0;
}