#include <iostream>

using namespace std;

int n, a[200006], b[200006];

int main()
{
cin>>n;

for(int i=1;i<n;i++)
{
    cin>>a[i];
    if(a[i]==0)
        i--;
}
for(int i=1;i<n;i++)
{
    cin>>b[i];
    if(b[i]==0)
        i--;
}
int index;
for(int i=1;i<n;i++)
{
    if(b[i]==a[1])
    {index=i;
     break;
    }
}
n--;
for(int i=0;i<n;i++)
{
    if(index+i == n+1)
        index-=n;
    if(a[i+1] != b[index+i])
    {
        cout<<"NO\n";
        return 0;
    }
}
cout<<"YES\n";
    return 0;
}