#include <stdio.h>
#include <vector>

int abs(int k)
{
	return k>0?k:-k;
}

int func(int k)
{
	std::vector< std::pair<int,int> > temp;
	for(int i=k;i<=200;i+=k) for(int j=1;j<=200;j++) temp.push_back(std::make_pair(i,j));
	
	printf("? %d\n",temp.size());
	fflush(stdout);
	for(int i=0;i<temp.size();i++) printf("%d %d ",temp[i].first,temp[i].second);
	printf("\n");
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int check[110];

int main()
{
	int S = func(1);
	check[0] = S;
	int min = 1, max = 7;
	int pivot = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		int p = (1<<h);
		int t = func(p);
		check[h] = t;
		if(t*p==S)
		{
			pivot = h;
			min = h+1;
		}
		else max = h-1;
	}
	int a = (1<<pivot);
	int y = abs((2*a)*check[pivot+1] - S)/a;
	int x = S/y;
	printf("! %d",2*(x+y)-4);
	fflush(stdout);
}