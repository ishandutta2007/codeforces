#include <iostream>

using namespace std;

int n, a[103], dmin=99999, df, ii;

int main()
{
cin>>n;
cin>>a[1]>>a[2];

for(int i=3;i<=n;i++)
{
    cin>>a[i];

    if(a[i]-a[i-2]<dmin)
        dmin=a[i]-a[i-2], ii=i-1;
}

for(int i=2;i<=n;i++)
{
    int j=i, k=i-1;
    if(i==ii)
        j++;
    if(i-1==ii)
        k--;
    if(df<a[j]-a[k])
        df=a[j]-a[k];
}

cout<<df<<'\n';

    return 0;
}