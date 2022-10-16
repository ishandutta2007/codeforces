#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

int a[105], sum, mins=999999999, n;
vector<int> v[102];

int main()
{int k;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        sum=0;
        for(int j=1; j<=a[i]; j++)
        {
            cin>>k;
            v[i].pb(k);
            sum+=k*5+15;
        }
        if(sum<mins)mins=sum;
    }
    cout<<mins;
    return 0;
}