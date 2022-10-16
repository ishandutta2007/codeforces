#include <iostream>
using namespace std;

int main()
{
    int n,m,d,x,y=0;
    cin>>n>>m>>d;

    int c[m+1];
    for(int i=1;i<=m;i++) { cin>>c[i]; y+=c[i]; }
    y=n-y;
    x=d-1;
    x*=(m+1);

    if(x<y) { cout<<"NO"<<endl; return 0; }
    cout<<"YES"<<endl;

    x=0;
    int a[n+1],cnt=0,cntr=0;
    for(int i=1;i<=n;i++)
    {
        if(x==y) cnt=1;
        if(cnt==0)
        {
            for(int j=1;j<=d-1;j++)
            {
                a[i]=0; i++; x++;
                if(x==y) break;
            }
            cnt=1;
        }
        cntr++;
        for(int j=1;j<=c[cntr];j++)
        {
            a[i]=cntr;
            i++;
        }
        i--;
        cnt=0;
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}