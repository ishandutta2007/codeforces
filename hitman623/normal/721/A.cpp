#include <iostream>

using namespace std;

int main()
{   char a[100];
    int n,i,p=0,q[100]={0},r=0,f=1;
    cin>>n;
    cin>>a;
    for(i=0;i<n;++i)
    {
        if(a[i]=='B') ++p;
        else if(p!=0) {q[r++]=p;p=0;}
    }
   if(p>0) q[r++]=p;
    cout<<r<<endl;
    for(i=0;i<r;++i)
        cout<<q[i]<<" ";
    return 0;
}