#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n;
int a[400009];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
       for(int i=0;i<n;i++)cin>>a[i];
       cout<<(n/2)*6<<endl;

       for(int i=0;i<n/2;i++)
       {
           int x=2*i+1,y=2*i+2;
           cout<<2<<" "<<x<<" "<<y<<endl;
           cout<<1<<" "<<x<<" "<<y<<endl;
           cout<<2<<" "<<x<<" "<<y<<endl;
           cout<<2<<" "<<x<<" "<<y<<endl;
           cout<<1<<" "<<x<<" "<<y<<endl;
           cout<<2<<" "<<x<<" "<<y<<endl;

       }

    }

    return 0;
}