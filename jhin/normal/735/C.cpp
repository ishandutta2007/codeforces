#include <bits/stdc++.h>

using namespace std;
double k,a[100000];long long n,n1,n2,temp,ans1=1,ans2=1;
int main()
{
    cin>>n;
   while (ans1<=n)
{   temp=ans1;
    ans1+=ans2;
    ans2=temp;
    n1++;
}
 cout<<n1-1;
    return 0;
}