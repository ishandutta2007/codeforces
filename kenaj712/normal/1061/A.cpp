#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c;
    cin>>a>>b;
    c=b/a;
    if(b%a!=0)
        c++;
    cout<<c;
	return 0;
}