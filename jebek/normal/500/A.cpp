#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,t,a[50000];

int main()
{
    cin>>n>>t;
    t--;
    for(int i=0;i<n-1;i++)
        cin>>a[i];
    int p=0;
    while(p<t && p<n-1)
    {
        p+=a[p];
    }
    if(p==t)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}