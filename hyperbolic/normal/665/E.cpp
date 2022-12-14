#include <stdio.h>

int C = 1;
int count[30000010];
int next[30000010][3];

void insert(int k, int node = 0, int h = 29)
{
	count[node]++;
	if(h==-1) return;
	
	int d = k/(1<<h);
	if(next[node][d]==0) next[node][d] = C++;
	insert(k%(1<<h),next[node][d],h-1);
}

int a,b;
int getValue(int k, int sum = 0, int node = 0, int h = 29)
{
	if(sum + (1<<(h+1)) -1 < b) return 0;
	if(sum >= b) return count[node];
	
	int s1 = 0, s2 = 0;
	if(next[node][1]!=0) s1 = getValue(k,sum + (1<<h)-((1<<h)&k),next[node][1],h-1);
	if(next[node][0]!=0) s2 = getValue(k,sum + ((1<<h)&k),next[node][0],h-1);
	return s1+s2;
}

int x[1000010];
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) x[i] ^= x[i-1];
	
	long long int ans = 0;
	insert(x[0]);
	for(int i=1;i<=a;i++)
	{
		ans += getValue(x[i]);
		insert(x[i]);
	}
	printf("%lld",ans);
}