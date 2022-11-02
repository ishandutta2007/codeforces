#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long tab1[1000005];
long long tab2[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    tab1[1]=2;
    tab2[1]=1;
    for(int x=2;x<=a;x++)
    {
        tab1[x]=(tab1[x-1]*(x+1))%mod;
        tab2[x]=(tab2[x-1]*x+x)%mod;
    }
    cout<<(tab1[a]-tab2[a]+mod)%mod;
	return 0;
}