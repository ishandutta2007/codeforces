#include<bits/stdc++.h>

int main()
{
	int a,b,c=0;
	scanf("%d%d",&a,&b);
	for(;;)
	{
		++c;
		if(a<c){puts("Vladik");break;}
		a-=c;
		++c;
		if(b<c){puts("Valera");break;}
		b-=c;
	}
}