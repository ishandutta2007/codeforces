#include <iostream>

using namespace std;

int main()
{
    int i,n,a[92];
    cin>>n;
    for(i=0;i<n;++i)
        cin>>a[i];
    if(n==1)
    {  if(a[0]==15) cout<<"DOWN";
       else if (a[0]==0) cout<<"UP";
       else
         cout<<-1;
    }
    else {
         if(a[n-1]<15 && a[n-1]>a[n-2]) cout<<"UP";
          else if (a[n-1]==0)cout<<"UP";
          else cout<<"DOWN";
    }
    return 0;
}