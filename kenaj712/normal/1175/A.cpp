#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    long long a,b;
    while(t--)
    {
        cin>>a>>b;
        long long ans=0;
        while(a!=0)
        {
            if(a%b==0)
            {
                a/=b;
                ans++;
            }
            else
            {
                ans+=a%b;
                a-=a%b;
            }
        }
        cout<<ans<<'\n';
    }
	return 0;
}