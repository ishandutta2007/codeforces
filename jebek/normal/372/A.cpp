#include <iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

long long n,ans,p,a[1000000];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    ans=n;
    p=n/2;
    for(int i=0;i<n/2;i++)
    {
        while(p<n)
        {
            if(a[i]*2<=a[p])
            {
                ans--;
                p++;
                break;
            }
            p++;
        }
    }
    cout<<ans<<endl;
}