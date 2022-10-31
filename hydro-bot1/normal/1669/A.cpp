// Hydro submission #626fccc808ff9c654f5249dc@1651494088609
#include<bits/stdc++.h>
using namespace std;
struct users{
	int level;
};
users k;
int u;
int main()
{
	scanf("%d",&u);
	for(int i=1;i<=u;i++)
	{
		cin>>k.level;
		if(k.level>=1900) printf("Division 1\n");
		if(k.level>=1600 and k.level<=1899) printf("Division 2\n");
		if(k.level>=1400 and k.level<=1599) printf("Division 3\n");
		if(k.level<=1399) printf("Division 4\n");
	}
	return 0;
}