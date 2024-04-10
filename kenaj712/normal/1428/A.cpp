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
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==c || b==d)
            cout<<abs(a-c)+abs(d-b);
        else
            cout<<abs(a-c)+abs(d-b)+2;
        cout<<'\n';
    }
	return 0;
}