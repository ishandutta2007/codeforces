#include <iostream>

using namespace std;

int main()
{
    long n,m,k,i,j,r[100000][3],f[100001]={0},q,a=-1;
    cin>>n>>m>>k;
    for(i=0;i<m;i++)
        cin>>r[i][0]>>r[i][1]>>r[i][2];
    for(i=0;i<k;++i)
    {cin>>q;f[q]=1;}
    for(i=0;i<m;++i)
    {
        if(f[r[i][0]]==1 && f[r[i][1]]==0)
             if(r[i][2]<a || a==-1) a=r[i][2];
         if(f[r[i][0]]==0 && f[r[i][1]]==1)
             if(r[i][2]<a || a==-1) a=r[i][2];
    }
    cout<<a;
        return 0;
}