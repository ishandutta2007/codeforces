#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<2*n;i++)cin>>a[i];
        sort(a,a+2*n);
        for(int i=0;i<n;i++)cout<<a[i]<<" "<<a[2*n-i-1]<<" ";
        cout<<endl;

    }

}