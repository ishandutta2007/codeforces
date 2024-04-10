#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,cntr=0;
        cin>>n;
        long long int a[n],b[n]={0};
        for(int k=0;k<n;k++)
        {
            long long int x,y;
            cin>>x;
            x+=k;
            if(x<0 && x%n!=0) y=x%n+n;
            else y=x%n;
            if(b[y]!=0) cntr++;
            b[y]++;
        }
        if(cntr==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}