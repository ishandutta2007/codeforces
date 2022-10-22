#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i,a,j;
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            cin>>a;
            if(a==1){n=i;m=j;}
        }
    }
    cout<<abs(n-3)+abs(m-3);
    return 0;
}