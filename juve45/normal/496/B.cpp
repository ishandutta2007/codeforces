#include <iostream>
#define dmax 1004
using namespace std;

int a[dmax], b[dmax], n;

void shift_b()
{
    int aux=b[1];
    for(int i=1;i<n;i++)
        b[i]=b[i+1];
    b[n]=aux;
}

bool ab()
{
    int s=(10-b[1])%10;
    b[1]=0;
    for(int i=2;i<=n;i++)
        b[i]=(b[i]+s)%10;

    int i=1;
    while(a[i]==b[i]) i++;
    if(a[i]>b[i]) return true;
    return false;

}

void acopy()
{
for(int i=1;i<=n;i++)
    a[i]=b[i];
}

int main()
{
cin>>n;
char ss[dmax];
cin>>ss;
a[1]=ss[0]-'0';

int s=10-a[1];
a[1]=0;

for(int i=2;i<=n;i++)
    a[i]=ss[i-1]-'0', a[i]=(a[i]+s)%10, b[i]=a[i];

for(int i=1;i<=n;i++)
{
    shift_b();
    if(ab()==true)
        acopy();
}

for(int i=1;i<=n;i++)
    cout<<a[i];


    return 0;
}