#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int r=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0)r++;
    }
    for(int i=0;i<r;i++)a[i]=-abs(a[i]);
    for(int i=r;i<n;i++)a[i]=abs(a[i]);
    bool bl=true;
    for(int i=1;i<n;i++)if(a[i]<a[i-1])bl=false;
    if(bl)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    }
    return 0;
}