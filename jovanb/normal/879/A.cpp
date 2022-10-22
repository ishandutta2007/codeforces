#include <bits/stdc++.h>

using namespace std;
int d[1000];
int dan[1000];
int main()
{
    long n,i;
    cin>>n;
    for(i=0;i<n;i++){cin>>dan[i]>>d[i];}
    for(i=1;i<n;i++){
        while(dan[i]<=dan[i-1])dan[i]+=d[i];
        }

    cout<<dan[n-1];
    return 0;
}