#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a;
    cin>>a;
    if(a==0)
    {
        cout<<0;
        return 0;
    }
    if(a%2==1)
        cout<<a/2+1;
    else
        cout<<a+1;
	return 0;
}