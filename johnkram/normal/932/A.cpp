#include<bits/stdc++.h>
using namespace std;
#define ll long long
char c[10005];
int main()
{
	cin>>c;
	cout<<c;
	reverse(c,c+strlen(c));
	cout<<c<<endl;
	return 0;
}