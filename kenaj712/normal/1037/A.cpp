#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,c=0;
    cin>>a;
    long long b=1;
    while(b<=a)
    {
        b*=2;
        c++;
    }
    cout<<c;
	return 0;
}