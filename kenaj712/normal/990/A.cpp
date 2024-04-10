#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<min((a%b)*d,(b-(a%b))*c);
	return 0;
}