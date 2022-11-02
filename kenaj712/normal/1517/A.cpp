#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long a;
        cin>>a;
        if(a%2050!=0)
            cout<<-1<<'\n';
        else
        {
            a /= 2050;
            int res = 0;
            while(a!=0)
            {
                res += a%10;
                a/=10;
            }
            cout<<res<<'\n';
        }
    }
	return 0;
}