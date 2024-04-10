/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int n,x,sum=0;
    cin>>n>>x;

    long long int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int i;
    for(i=1;i<=n;i++)
    {
        sum+=a[n+1-i];
        if(sum<i*x) break;
    }

    cout<<i-1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}