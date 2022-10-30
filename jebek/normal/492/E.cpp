#include <iostream>
#include<algorithm>

using namespace std;

int n,m,x,y,a,b,MAX,p,t[2000000],f[2000000];

int main()
{
    cin>>n>>m>>x>>y;
    a=0;b=0;
    for(int i=0;i<n;i++)
    {
        f[a]=b;
        a=(a+x)%n;
        b=(b+y)%n;
    }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        t[(b-f[a]+n)%n]++;
    }
    for(int i=0;i<n;i++)
        if(t[i]>MAX)
        {
            MAX=t[i];
            p=i;
        }
    cout<<0<<" "<<p<<endl;
}