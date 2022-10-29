#include<bits/stdc++.h>
#define rep(i,j,k) for(int i =j; i<=k; i++)
using namespace std;

int main(){
    cout<<2000<<endl;
    rep(i,1,1000)
        printf("%d 1 %d 2\n", i,i);
    rep(i,1,1000)
        printf("%d 1 %d 2\n", 1001-i,1001-i);
    return 0;
}