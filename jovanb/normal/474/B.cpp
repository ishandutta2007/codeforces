#include <bits/stdc++.h>

using namespace std;
long poz[1000005];
int main()
{
    long i,j,n,a,b;
    cin>>n;
    cin>>a;
    for(i=1;i<=a;i++)poz[i]=1;
    for(i=1;i<n;i++){
        cin>>b;
        for(j=a+1;j<=a+b;j++)poz[j]=i+1;
        a+=b;
    }
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        cout<<poz[a]<<endl;
    }
    return 0;
}