#include <bits/stdc++.h>

using namespace std;

long long n, k, c, a[6], b[6], m;

int main()
{
    cin>>n>>m;

    for(int i=0;i<5;i++)
    {
        a[i]=n/5;
        c=n-(n/5)*5;
        if(c>=i)
            a[i]++;
        b[i]=m/5;
        c=m-(m/5)*5;
        if(c>=i)
            b[i]++;
    }
    a[0]--;
    b[0]--;
    cout<<a[0]*b[0]+a[1]*b[4]+a[2]*b[3]+a[3]*b[2]+a[4]*b[1]<<'\n';


    return 0;
}