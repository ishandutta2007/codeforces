#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum[200009];
int main()
{
    int n,t,k;
    cin>>n>>t>>k;
    int l=1,r=n;
    while(r>l)
    {
        int mid=(l+r)/2;
        cout<<"? "<<1<<" "<<mid<<endl;
        fflush(stdout);
        int x;
        cin>>x;
        int p=mid-x;
        if(p>=k)r=mid;
        else l=mid+1;
    }
    cout<<"! "<<l<<endl;
    fflush(stdout);
    return 0;
}