#include<bits/stdc++.h>
using namespace std;
int n,m,i;
int main()
{
	cin>>n;
	m=(n+8)/9;
	for(i=0;i<m;i++)putchar('9');
	puts("");
	for(i=0;i<m;i++)putchar('9');
	for(i=1;i<m;i++)putchar('0');
	puts("1");
	return 0;
}