#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int freq[n];
	for(int i=0;i<n;i++)
		freq[i]=0;
	int count=0,max=0;
	for(int i=0;i<2*n;i++)
	{
	int num;
	scanf("%d",&num);
	freq[num-1]++;
	if(freq[num-1]==1)
	count++;
	if(freq[num-1]==2)
	count--;
	if(count>max)
	max=count;
	}
	printf("%d",max);
    return 0;
}