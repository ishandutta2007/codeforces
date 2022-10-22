#include <bits/stdc++.h>

using namespace std;
int a[1009];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
bool bl=false;
    sort(a,a+n);
for(int i=0;i<n-1;i++)if(a[i+1]==a[i]+1){bl++;break;}
if(bl)cout<<2<<endl;
else cout<<1<<endl;

    }
    return 0;
}