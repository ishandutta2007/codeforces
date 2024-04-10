#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	cin>>n>>m;
	if(n<30)m=m%(1<<n);
	cout<<m<<endl;
	return 0;
}