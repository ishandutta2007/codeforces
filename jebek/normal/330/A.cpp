#include <iostream>

using namespace std;

int main()
{
    int n,m,ans,a[20]={0},b[20]={0},k=0,p=0;
    char c;
    cin>>n>>m;
    ans=m*n;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>c;
            if(c=='S')
            {
                a[i]=1;
                b[j]=1;
            }
        }
    for(int i=0;i<n;i++)
        if(a[i]==1)
            k++;
    for(int j=0;j<m;j++)
        if(b[j]==1)
        p++;
    ans-=k*p;
    cout<<ans<<endl;
}