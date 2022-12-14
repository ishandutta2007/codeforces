#include<cstdio>
#include<cstring>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m;
string a;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a;
	int s=0;
	for(int i=0;i<a.size();i++)
		s+=a[i]=='B'&&(i==0||a[i-1]!='B');
	cout<<s<<endl;
	return 0;
}