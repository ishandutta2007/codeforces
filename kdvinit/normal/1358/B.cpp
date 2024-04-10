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
        int n;
        cin>>n;
        int a[n+1];
        a[n]=0;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        int i;
        for(i=n-1;i>=0;i--)
        {
            if(a[i]<=i+1) break;
        }
        cout<<i+2<<endl;
    }
    return 0;
}