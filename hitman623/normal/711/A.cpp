#include <iostream>
using namespace std;

int main()
{
  int n,f=0,j=0,i;
        cin>>n;
    char a[1000][6];
    for(j=0;j<n;j++)
    {  cin>>a[j];
    }
    for(i=0;i<n;++i)
    {
      if(a[i][0]=='O' && a[i][1]=='O') {a[i][0]='+'; a[i][1]='+';f=1;break;}
       if(a[i][3]=='O' && a[i][4]=='O') {a[i][3]='+'; a[i][4]='+';f=1;break;}
    }
    if(f==0) cout<<"NO";
    else
    {  cout<<"YES"<<endl;
        for(i=0;i<n;++i)
    {
        cout<<a[i]<<endl;
    }
    }
    return 0;
}