#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    if(min(b,c)>=a)
        cout<<"Yes";
    else
        cout<<"No";
	return 0;
}