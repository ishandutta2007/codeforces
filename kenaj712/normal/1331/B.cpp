#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=2;x<=1000;x++)
    {
        while(a%x==0)
        {
            cout<<x;
            a/=x;
        }
    }
	return 0;
}