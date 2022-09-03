#include<cstdio>

int main()
{
	char t;
	int a,b;
	a=b=0;
	while(~(t=getchar()))
	{
		if(t=='Q')a+=9;
		if(t=='R')a+=5;
		if(t=='B')a+=3;
		if(t=='N')a+=3;
		if(t=='P')a+=1;
		if(t=='q')b+=9;
		if(t=='r')b+=5;
		if(t=='b')b+=3;
		if(t=='n')b+=3;
		if(t=='p')b+=1;
	}
	puts(a>b?"White":a<b?"Black":"Draw");
}