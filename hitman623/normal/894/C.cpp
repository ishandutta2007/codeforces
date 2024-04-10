#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define h 1000000007
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
long n,a[1005],i;
int main()
{
    io
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]%a[0])
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<2*n<<"\n";
    for(i=0;i<n;++i)
    cout<<a[i]<<" "<<a[0]<<" ";
    return 0;
}