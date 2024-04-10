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
        long long a,b;
        cin>>a>>b;
        if(a<=b)
        {
            a--;
            cout<<(a*(a+1)/2)+1<<'\n';
        }
        else
        {
            cout<<b*(b+1)/2<<'\n';
        }
    }
	return 0;
}