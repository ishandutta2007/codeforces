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
        long long c=a%b;
        if(c==0)
            cout<<0;
        else
            cout<<b-c;
        cout<<'\n';
    }
	return 0;
}