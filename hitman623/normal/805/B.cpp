#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long n,i;
    cin>>n;
    for(i=0;i<n;++i)
    if(i%4<=1)
    cout<<'a';
    else cout<<'b';
    return 0;
}