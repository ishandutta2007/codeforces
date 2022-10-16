#include <iostream>

using namespace std;
int n, k, a[102];

int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)
{cin>>a[i];
}

if(a[k]>0)
while(a[k]==a[k+1])k++;
else while(a[k]<=0 && k>0) k--;
cout<<k;

    return 0;
}