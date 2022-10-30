#include <iostream>
#include<algorithm>

using namespace std;

int n,m,p,ind,ind1,a[300000],b[300000],MAX;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    MAX=2*n-2*m;
    ind=n;
    ind1=m;
    p=m-1;
    for(int i=n-1;i>-1;i--)
    {
        while(p>=0 && b[p]>=a[i])
            p--;
      //  cout<<i<<" "<<p<<endl;
        if(2*n-2*m+n-i-m+p+1>=MAX)
        {
            ind=i;
            ind1=p+1;
            MAX=2*n-2*m+n-i-m+p+1;
        }
    }
   // cout<<MAX<<" "<<ind<<" "<<ind1<<endl;
    cout<<2*n+n-ind<<":"<<2*m+m-ind1<<endl;
}