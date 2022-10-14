#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
int n,x,sum,a[102],a2[102];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];a2[a[i]]=i;}
    for(int i=1;i<=n;i++)cout<<a2[i]<<" ";
    return 0;
}