#include<bits/stdc++.h>
using namespace std;
struct Time
{
	int Hou,Min;
	void add()
	{
		Min++;
		if(Min>=60)
			Min=0,
			Hou++;
		Hou%=24;
		return ;
	}
}Tim;
int main()
{
	scanf("%d:%d",&Tim.Hou,&Tim.Min);
	int x;
	cin>>x;
	while(x--)
		Tim.add();
	printf("%02d:%02d",Tim.Hou,Tim.Min);
	return 0;
}