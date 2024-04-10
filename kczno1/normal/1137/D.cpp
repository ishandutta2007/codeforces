#include<bits/stdc++.h>
using namespace std;

int read()
{
	fflush(stdout);
	int k;
	cin>>k;
	string s;
	for(int i=k;i--;)cin>>s;
	return k;
}

int main()
{
	while(1)
	{
		puts("next 0 1");
		read();
		puts("next 1");
		if(read()==2)break;
	}
	while(1)
	{
		puts("next 0 1 2 3 4 5 6 7 8 9");
		if(read()==1)break;
	}
	puts("done");
}