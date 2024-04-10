#include <iostream>
using namespace std;

int main()
{
    int T;      //Input of number of test cases
    cin>>T;

    for(int j=1;j<=T;j++)
    {
        int n;
        cin>>n;

        int a[n+1];
        for(int i=1;i<=n;i++) cin>>a[i];

        int ans[n+1];
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            {
               ans[i-1]=-a[i];
            }
            else
            {
               ans[i+1]=a[i];
            }
        }

        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}