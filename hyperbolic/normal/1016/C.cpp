#include <stdio.h>

int a;
long long int X1[300010],X2[300010],X3[300010];
long long int Y1[300010],Y2[300010],Y3[300010];
long long int func1(int s, int t)
{
	long long int s1 = X2[s] + (t-1)*X1[s]; // s ~ a : a-s+1
	long long int s2 = Y3[s] + (a-s+t)*Y1[s];
	return s1+s2;
}
long long int func2(int s, int t)
{
	long long int s1 = Y2[s] + (t-1)*Y1[s]; // s ~ a : a-s+1
	long long int s2 = X3[s] + (a-s+t)*X1[s];
	return s1+s2;
}
int x[300010],y[300010];
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=a;i>=1;i--) X1[i] = X1[i+1] + x[i];
	for(int i=a;i>=1;i--) Y1[i] = Y1[i+1] + y[i];
	
	for(int i=a;i>=1;i--) X2[i] = X2[i+1] + X1[i];
	for(int i=a;i>=1;i--) Y2[i] = Y2[i+1] + Y1[i];
	for(int i=1;i<=a;i++) X3[i] = (a-i+2)*X1[i] - X2[i];
	for(int i=1;i<=a;i++) Y3[i] = (a-i+2)*Y1[i] - Y2[i];
	
	
	long long int ans = 0;
	long long int sum = 0;
	int i = 1;
	long long int count = 1;
	for(;i<=a;)
	{
		ans = ans > func1(i,count) + sum? ans : func1(i,count) + sum;
		//printf("%lld %lld!!\n",func1(i,count),sum);
		sum += count*x[i], count++;
		sum += count*y[i], count++, i++;
		if(i>a) break;
		ans = ans> func2(i,count) + sum? ans : func2(i,count) + sum;
		//printf("%lld %lld??\n",func2(i,count),sum);
		sum += count*y[i], count++;
		sum += count*x[i], count++, i++;
	}
	printf("%lld",ans-X1[1]-Y1[1]);
}