#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	 string s;
	 int k;
	 cin>>s>>k;
	if ((s=="front" && k==1) || (s=="back" && k==2)) {cout<<'L';} else {cout<<'R';}
	return 0;
}