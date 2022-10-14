#include <iostream>
#include <math.h>

using namespace std;
long long n,m,x,cnt;bool lu=true;
int main()
{
    cin>>n;

    m=int (log10(n))+1;
    for(int i=0;i<m;i++)
    {if(n%10==7||n%10==4)cnt++;n/=10;}
     if(cnt==4||cnt==7)cout<<"YES";
     else  cout<<"NO";

    return 0;
}