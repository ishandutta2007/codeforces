#include <stdio.h>

int count[30][200010];
char x[200010];

int func(int s, int t, int type)
{
	if(s==t)
	{
		if(x[s]==type+'a') return 0;
		else return 1;
	}
	else
	{
		int h = (s+t)/2;
		int s1 = func(s,h,type+1);
		int s2 = func(h+1,t,type+1);
		int ans1 = s1 + (t-h-(count[type][t]-count[type][h]));
		int ans2 = s2 + (h-s+1-(count[type][h]-count[type][s-1]));
		return ans1<ans2?ans1:ans2;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		for(int i=0;i<26;i++) for(int j=0;j<=a;j++) count[i][j] = 0;
		for(int i=1;i<=a;i++) count[x[i]-'a'][i]++;
		for(int i=0;i<26;i++) for(int j=1;j<=a;j++) count[i][j] += count[i][j-1];
		printf("%d\n",func(1,a,0));
	}
}