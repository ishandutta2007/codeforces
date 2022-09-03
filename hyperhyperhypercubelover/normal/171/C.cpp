#include<cstdio>

int mixb[100];
int mixbn;

int main()
{
	int car,i;
	int choco;
	int flour=1;
	int egg=1;
	scanf("%d",&car);
	mixbn++;
	for(i=0;i<car;i++)
	{
		scanf("%d",&choco);
		mixb[mixbn++]=choco;
		mixb[mixbn-1]*=flour;
		choco=mixb[--mixbn];
		mixb[mixbn-1]+=choco;
		mixb[mixbn++]=flour;
		mixb[mixbn-1]+=egg;
		flour=mixb[--mixbn];
	}
	printf("%d",mixb[0]);
}