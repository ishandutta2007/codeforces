#include <iostream>

using namespace std;
int n, a[100009], sol[100009];
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
int max=a[n];
sol[n]=0;
for(int i=n-1;i>0;i--)
{
    if(a[i]>max) sol[i]=0, max=a[i];
    else{
        sol[i]=max-a[i]+1;
    }
}

for(int i=1;i<=n;i++)
    cout<<sol[i]<<" \n"[i==n];

    return 0;
}