#include <iostream>

using namespace std;

long long n;
long long a[100009];

int main()
{

cin>>n;
a[n+1]=0LL;
for(int i=1;i<=n;i++)
    cin>>a[i];

for(int i=1;i<=n;i++)
    cout<<a[i]+a[i+1]<<' ';



    return 0;
}