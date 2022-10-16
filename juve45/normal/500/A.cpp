#include <iostream>

using namespace std;

int n, k, a[30003], use[30003];

int main()
{
    cin>>n>>k;
    int x;
    for(int i=1; i<n; i++)
    {
        cin>>x;
        a[i]=x+i;
    }

    int i=1;
    if(a[i]==k)
        {
            cout<<"YES\n";
            return 0;
        }
    while(a[i]!=k && i<n)
    {
        i=a[i];
        if(a[i]==k)
        {
            cout<<"YES\n";
            return 0;
        }
    }

    cout<<"NO\n";
    return 0;
}