#include <bits/stdc++.h>

using namespace std;
long bjuti[1000];
int main()
{
    long long n,k=1,i,x=0;
    cin>>n;
    while(x<=n){
        x=(pow(2,k)-1)*pow(2,k-1);
        bjuti[k]=x;
        k++;
    }
    for(i=k-1;i>=1;i--){
        if(n%bjuti[i]==0){cout<<bjuti[i];return 0;}
    }
    return 0;
}