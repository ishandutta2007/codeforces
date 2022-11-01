#include <iostream>
#include<algorithm>

using namespace std;

int n,k,a,t,m;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a%2==1)
            t++;
    }
    if(n==k)
    {
        if(t%2==1)
            cout<<"Stannis";
        else
            cout<<"Daenerys";
        return 0;
     }
    m=n-k;
    if(m/2>=t)
    {
        cout<<"Daenerys"<<endl;
        return 0;
    }
    if(n-t<=(m+1)/2 && k%2==1)
    {
        cout<<"Stannis"<<endl;
        return 0;
    }
    if(m%2==0 || (m/2>=n-t && k%2==0))
    {
        cout<<"Daenerys"<<endl;
        return 0;
    }
    cout<<"Stannis"<<endl;
}