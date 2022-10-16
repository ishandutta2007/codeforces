#include <iostream>

using namespace std;

int n, k, K[100009], a[100009];

int main()
{
cin>>n>>k;

for(int i=1;i<=n;i++)
{
    cin>>a[i];
    K[i%k]+=a[i];
}
int kmax=100000009, imax;
for(int i=1;i<=k;i++)
{
    if(K[i%k]<kmax)
        kmax=K[i%k], imax=i;
}

cout<<imax;
    return 0;
}