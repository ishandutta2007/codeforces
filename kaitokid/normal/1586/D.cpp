#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int df[1009];
int main()
{

    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        cout<<"? ";
        for(int j=1;j<n;j++)cout<<i<<" ";
        cout<<n<<endl;
        fflush(stdout);
        int r;
        cin>>r;
        df[r]=n-i;
    }
    for(int i=1;i<n;i++)
    {
        cout<<"? ";
        for(int j=1;j<n;j++)cout<<n<<" ";
        cout<<i<<endl;
        fflush(stdout);
        int r;
        cin>>r;
        df[r]=-(n-i);
    }
    int mn=0;
    for(int i=1;i<=n;i++)mn=min(mn,df[i]);
    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<df[i]-mn+1<<" ";
    cout<<endl;
    fflush(stdout);
    return 0;
}