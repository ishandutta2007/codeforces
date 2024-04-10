#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    char a[101];int m=0,n,i,f='a';
    cin>>a;
    m=fabs(a[0]-f);
     if(m>13) m=26-m;
    for(i=1;a[i]!=0;++i)
    {
        n=fabs(a[i]-a[i-1]);
        if(n>13) n=26-n;
        m+=n;
    }
    cout<<m;
    return 0;
}