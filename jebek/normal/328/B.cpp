#include <iostream>

#include<string>
using namespace std;

int main()
{
    string p,n;
    int a[10]={0},b[10]={0},k,m=10000000;
    cin>>n;
    cin>>p;
    for(int i=0;i<n.size();i++)
    {
        k=int(n[i]-'0');
        if(k==9)
            b[6]++;
        else if(k==5)
            b[2]++;
        else
            b[k]++;
    }
    for(int i=0;i<p.size();i++)
    {
        k=int(p[i]-'0');
        if(k==9)
            a[6]++;
        else if(k==5)
            a[2]++;
        else
            a[k]++;
    }
    for(int i=0;i<10;i++)
    {
        if(i!=5 && i!=9 && b[i]!=0)
        {
            k=a[i]/b[i];
            if(k<m)
                m=k;
        }
    }
    cout<<m;
}