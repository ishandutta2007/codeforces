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
        if(c+d>a+b || (d>min(a,b)))
            cout<<"No";
        else
            cout<<"Yes";
        cout<<'\n';
    }
	return 0;
}