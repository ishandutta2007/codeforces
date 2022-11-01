#include <iostream>
#include<algorithm>

using namespace std;

long long n,m,a[5000];

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>a[i];
    sort(a,a+m);
    if(a[0]==1 || a[m-1]==n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<m-2;i++)
        if(a[i+1]==a[i]+1 && a[i+2]==a[i+1]+1)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    cout<<"YES"<<endl;
}