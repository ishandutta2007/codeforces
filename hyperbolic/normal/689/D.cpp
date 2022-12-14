#include <stdio.h>
#define MIN -1000000001
#define MAX 1000000001
int max(int a, int b)
{
	return a>b?a:b;
}
int min(int a, int b)
{
	return a<b?a:b;
}
long long int ans = 0;
int a,C;
int x[1000010],y[1000010];
int func1(int s, int t)
{
	int ans = MIN;
	s+=C,t+=C;
	while(s<t)
	{
		if(s%2==1) ans = ans>x[s]?ans:x[s],s++;
		if(t%2==0) ans = ans>x[t]?ans:x[t],t--;
		s/=2,t/=2;
	}
	if(s==t) ans = ans>x[s]?ans:x[s];
	return ans;
}
int func2(int s, int t)
{
	int ans = MAX;
	s+=C,t+=C;
	while(s<t)
	{
		if(s%2==1) ans = ans<y[s]?ans:y[s],s++;
		if(t%2==0) ans = ans<y[t]?ans:y[t],t--;
		s/=2,t/=2;
	}
	if(s==t) ans = ans<y[s]?ans:y[s];
	return ans;
}
int findMax(int k)
{
	//k~a
	int min = k, max = a;
	int ans = -1;
	while(min<=max)
	{
		int h = (min+max)/2,s,t;
		s = func1(k,h);
		t = func2(k,h);
		if(s==t) ans = h,min = h+1;
		else if(s>t) max = h-1;
		else min = h+1;
	}
	return ans;
}
int findMin(int k)
{
	//k~a
	int min = k, max = a;
	int ans = -1;
	while(min<=max)
	{
		int h = (min+max)/2,s,t;
		s = func1(k,h);
		t = func2(k,h);
		if(s==t) ans = h,max = h-1;
		else if(s>t) max = h-1;
		else min = h+1;
	}
	return ans;
}
int main()
{
	scanf("%d",&a);
	for(C=1;C<a;C*=2); C--;
	for(int i=1;i<=a;i++) scanf("%d",&x[C+i]);
	for(int i=C+a+1;i<=2*C-1;i++) x[i] = MIN;
	for(int i=1;i<=a;i++) scanf("%d",&y[C+i]);
	for(int i=C+a+1;i<=2*C-1;i++) y[i] = MAX;
	
	for(int i=C;i>=1;i--) x[i] = x[2*i]>x[2*i+1]?x[2*i]:x[2*i+1];
	for(int i=C;i>=1;i--) y[i] = y[2*i]<y[2*i+1]?y[2*i]:y[2*i+1];
	for(int i=1;i<=a;i++)
	{
		int b,c;
		b = findMax(i);
		c = findMin(i);
		if(b==-1) continue;
		else ans+=(b-c+1);
	}
	printf("%I64d",ans);
}