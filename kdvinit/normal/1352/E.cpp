/*
9
3 1 4 1 5 9 2 6 5
*/


#include <iostream>
using namespace std;

void show(int a[],int strt,int nd)
{
    for(int i=strt;i<=nd;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],freq[n+1]={0},spec[n+1]={0},mx=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            int x=a[i];
            freq[x]++;
            mx=max(mx,x);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            //cout<<i+1<<endl;
            int temp=a[i];
            for(int j=i+1;j<n;j++)
            {
                temp+=a[j];
                if(temp>mx) break;
                if(spec[temp]==0) ans+=freq[temp];
                spec[temp]=1;
            }
        }
        //cout<<mx<<endl;
        //show(freq,1,n);
        //show(spec,1,n);
        cout<<ans<<endl;
    }
    return 0;
}