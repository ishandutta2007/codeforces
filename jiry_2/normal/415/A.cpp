#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int x[101],n,m,k,y[101];
    cin>>n>>m;
    memset(x,0x00,sizeof x);
    for (int i=1;i<=m;i++)
    {
        cin>>k;
        for (int j=k;j<=n;j++){
            if (x[j]==0) x[j]=k;
        }
    }
    for (int i=1;i<=n;i++) cout<<x[i]<<" "; cout<<endl;
    return 0;
}