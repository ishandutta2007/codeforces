#include <iostream>
#include<algorithm>

using namespace std;

int n,a[200000],t,last,ind;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
            t++;
    }
    if(a[n-1]==1 || (t==2 && a[n-2]==0))
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if(n==1 || a[n-2]==1 || (n==3 && a[0]==0))
    {
        for(int i=0;i<n-1;i++)
            cout<<a[i]<<"->";
        cout<<a[n-1]<<endl;
        return 0;
    }
    if(a[n-3]==0)
    {
        for(int i=0;i<n-3;i++)
        {
            cout<<a[i]<<"->";
            if(i==0)
                last=a[0];
            else if(last==1 && a[i]==0)
                last=0;
            else
                last=1;
        }
        if(last==1)
            cout<<a[n-3]<<"->"<<a[n-2]<<"->"<<a[n-1]<<endl;
        else
            cout<<'('<<a[n-3]<<"->"<<a[n-2]<<")->"<<a[n-1]<<endl;
        return 0;
    }
    t=0;
    for(int i=n-1;i>-1;i--)
    {
        if(a[i]==0)
            t++;
        if(t==3)
        {
            ind=i;
            break;
        }
    }
    last=1;
    for(int i=0;i<ind;i++)
    {
            cout<<a[i]<<"->";
            if(i==0)
                last=a[0];
            else if(last==1 && a[i]==0)
                last=0;
            else
                last=1;
    }
    if(last==1)
    {
        cout<<a[ind]<<"->((";
        for(int i=ind+1;i<n-3;i++)
            cout<<a[i]<<"->";
        cout<<a[n-3]<<")->"<<a[n-2]<<")->"<<a[n-1]<<endl;
        return 0;
    }
    cout<<"("<<a[ind]<<"->((";
    for(int i=ind+1;i<n-3;i++)
        cout<<a[i]<<"->";
    cout<<a[n-3]<<")->"<<a[n-2]<<"))->"<<a[n-1]<<endl;
}