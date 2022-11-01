#include <iostream>
#include<algorithm>

using namespace std;

int p,p1,a[200000],x,y,n,m;
bool mark1,mark2,mark3,mark4;

bool check1(int k)
{
    p=0;
    for(int i=0;i<n;i++)
    {
        while(a[i]-a[p]>k)
            p++;
        if(a[i]-a[p]==k && (a[p]>=x || m-a[i]>=x))
            return true;
    }
    return false;
}

bool check(int k)
{
    p=0;
    for(int i=0;i<n;i++)
    {
        while(a[i]-a[p]>k)
            p++;
        if(a[i]-a[p]==k)
            return true;
    }
    return false;
}

int main()
{
    cin>>n>>m>>x>>y;
    for(int i=0;i<n;i++)
        cin>>a[i];
    mark1=check(x);
    mark2=check(y);
    mark4=check1(y-x);
    p1=p;
    if(x+y<=m){
        mark3=check(x+y);
        if(mark3)
            p1=p;
    }
    if(mark1 || mark2)
    {
        if(mark1 && mark2)
            cout<<0<<endl;
        else if(mark1)
            cout<<1<<endl<<y<<endl;
        else
            cout<<1<<endl<<x<<endl;
    }
    else if(mark3)
        cout<<1<<endl<<a[p1]+x<<endl;
    else if(mark4 && a[p1]>=x)
        cout<<1<<endl<<a[p1]-x<<endl;
    else if(mark4)
        cout<<1<<endl<<a[p1]+y<<endl;
    else
        cout<<2<<endl<<x<<" "<<y<<endl;
}