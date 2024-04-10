#include <bits/stdc++.h>

using namespace std;
int n, a[1000];
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}

if(a[n]==0)
{
    cout<<"UP";
    return 0;
}
if(a[n]==15)
{
    cout<<"DOWN";
    return 0;
}

if(n==1)
{
    cout<<-1;
    return 0;
}

if(a[n]>a[n-1])
{
    cout<<"UP";
}else cout<<"DOWN";

}