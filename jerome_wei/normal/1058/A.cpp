#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a==1)flag=0;
	}
	if(flag)printf("EASY\n");
	else printf("HARD\n");
}