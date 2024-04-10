#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k;
        cin>>n>>k;
        if(k%2==0)
        {
            if(n%2==1 || n<k) cout<<"NO"<<endl;
            else
            {
                cout<<"YES"<<endl;
                for(int i=0;i<k-1;i++) cout<<1<<" ";
                cout<<n+1-k<<endl;
            }
            continue;
        }
        else
        {
            if(n%2==1 && n>=k)
            {
                cout<<"YES"<<endl;
                for(int i=0;i<k-1;i++) cout<<1<<" ";
                cout<<n+1-k<<endl;
                continue;
            }
            if(n%2==0 && n>=2*k)
            {
                cout<<"YES"<<endl;
                for(int i=0;i<k-1;i++) cout<<2<<" ";
                cout<<n+2-2*k<<endl;
                continue;
            }
            cout<<"NO"<<endl;
            continue;
        }
    }
    return 0;
}