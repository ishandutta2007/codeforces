#include <bits/stdc++.h>
using namespace std;
bool fun(int a,int b,int c)
{
	if(c == 0)
		return a == b;
	if((b-a)%c == 0)
		return ((b-a)/c >= 0);
	return 0;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(fun(a,b,c))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}