#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x=sqrt(n+n-1);
        cout<<(x-1)/2<<endl;
    }
    return 0;
}