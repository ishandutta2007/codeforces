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
        int a[n],ans=0,cntr=0;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            cntr++;
            if(cntr>=a[i])
            {
                ans++;
                cntr=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}