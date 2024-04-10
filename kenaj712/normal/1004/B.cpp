#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b;
    for(int x=0;x<b;x++)
        cin>>c>>d;
    for(int x=0;x<a;x++)
        cout<<x%2;
	return 0;
}