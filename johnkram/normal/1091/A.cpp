#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b>>c;
	cout<<min(min(a+1,b),c-1)*3<<endl;
	return 0;
}