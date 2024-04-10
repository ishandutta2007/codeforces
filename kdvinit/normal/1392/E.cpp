/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n;

void solve(long long int k)
{
    int x=1,y=1;
    cout<<x<<" "<<y<<endl;
    for(int i=1;i<=2*n-2;i++)
    {
        int z=k%2;
        int w=x%2;

        if(w==z) y++;
        else x++;

        cout<<x<<" "<<y<<endl;
        k/=2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;

    long long int p2[2*n+1],val=1;
    p2[0]=0;
    for(int i=1;i<=2*n;i++)
    {
        p2[i]=val;
        val*=2;
    }

    for(int i=0;i<n;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++) cout<<0<<" ";
            cout<<endl;
        }
        else
        {
            for(int j=0;j<n;j++) cout<<p2[j+i]<<" ";
            cout<<endl;
        }
    }

    int q;
    cin>>q;
    while(q--)
    {
        long long int k;
        cin>>k;
        solve(k);
        cout<<endl;
    }

    return 0;
}