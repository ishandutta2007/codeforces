#include <bits/stdc++.h>

using namespace std;
int n,c=1,j,x;
int a[1000003];
int main()
{
    ios_base::sync_with_stdio(false);
 cin>>n;
 for(int i=0;i<n;i++)cin>>a[i];
 j=n-1;while(j>0){x=a[j];while(x&&j){x=max(x,a[j]);j--,x--;}while((!a[j])&&j)c++,j--;}
 cout<<c;
    return 0;
}