#include <iostream>

using namespace std;

int main()
{
    long n,a,b,k,i,c=0,l=-1,e[200000];
    cin>>n>>a>>b>>k;
    char d[200001];
    cin>>d;
    for(i=0;i<n;++i)
    {
        if(d[i]=='1')
        {
         l=i;
        }
        else
        {
          if(i-l>=b) {e[c++]=i+1;l=i;d[i]='1';}
        }
    }
    //cout<<d;
    cout<<c-a+1<<endl;
    for(i=0;i<c-a+1;++i)
        cout<<e[i]<<" ";
    return 0;
}