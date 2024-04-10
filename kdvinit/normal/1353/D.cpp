/*
KDVINIT

My Test Case -

Mistakes -

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

void show(int a[],int strt,int nd)
{
	for(int i=strt;i<=nd;i++) cout<<a[i]<<" ";
	cout<<endl;
}

int pos(int a[],int n,int &i)
{
    int cntind=0,index[n],mx=0,cntr=0;
    for(int j=1;j<=n;j++)
    {
        if(a[j]==0 && j!=n) {cntr++; continue;}
        if(a[j]==0 && j==n) {cntr++; j++;}
        if(a[j]!=0 || j>n)
        {
            if(cntr==mx)
            {
                index[++cntind]=j-1;
            }
            if(cntr>mx)
            {
                mx=cntr;
                cntind=0;
                index[++cntind]=j-1;
            }
            cntr=0;
        }
    }
    mx/=2;
    for(int j=1;j<=cntind;j++)
    {
        int x=index[j]-mx;
        a[x]=i;
        i++;
    }
    i--;
}


int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1]={0};
        for(int i=1;i<=n;i++)
        {
            pos(a,n,i);
        }
        show(a,1,n);
    }
    return 0;
}