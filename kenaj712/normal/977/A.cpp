#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    while(b--)
    {
        if(a%10==0)
            a/=10;
        else
            a--;
    }
    cout<<a;
	return 0;
}