#include <iostream>
#include<algorithm>
#include<map>

using namespace std;

int n,a[200000],b[200000];
map<int,int>t;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        t[a[i]]++;
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>b[i];
        t[b[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        if(t[a[i]])
            cout<<a[i]<<endl,t[a[i]]=0;
    }
    for(int i=0;i<n-1;i++)
        t[b[i]]++;
    for(int i=2;i<n;i++)
    {
        int c;
        cin>>c;
        t[c]--;
    }
    for(int i=0;i<n-1;i++)
    {
        if(t[b[i]])
            cout<<b[i]<<endl,t[b[i]]=0;
    }
}