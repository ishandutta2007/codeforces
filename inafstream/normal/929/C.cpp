#include <bits\stdc++.h>

using namespace std;


struct plr
{
	long long fr,ky;
}p[1004];

bool cmp(plr x,plr y)
{
	return x.ky<y.ky;
}

long long cnt[100004][5];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	int i;
	
	for (i=1;i<=a;i++)
	{
		scanf("%d",&p[i].ky);
		p[i].fr=1;
		
		cnt[p[i].ky][p[i].fr]++;
	}
	
	for (i=a+1;i<=a+b;i++)
	{
		scanf("%d",&p[i].ky);
		p[i].fr=2;
		
		cnt[p[i].ky][p[i].fr]++;
	}
	
	for (i=a+b+1;i<=a+b+c;i++)
	{
		scanf("%d",&p[i].ky);
		p[i].fr=3;
		
		cnt[p[i].ky][p[i].fr]++;
	}
	
	for (i=1;i<=100000;i++)
	{
		int j;
		
		for (j=1;j<=3;j++) cnt[i][j]+=cnt[i-1][j];
	}
	sort(p+1,p+a+b+c+1,cmp);
	
	long long ans=0;
	
	for (i=1;i<=a+b+c;i++)
	{
		int j;
		
		for (j=i+1;j<=a+b+c;j++)
		{
			if (p[i].ky*2<p[j].ky) break;
			if (p[i].fr==1&&p[j].fr==1) continue;
			
			long long r=min(p[i].ky*2,p[j].ky-1),l=max(p[i].ky+1,(p[j].ky+1)/2)-1;
			
			if (r<l) continue;
			
			int ta=1,tb=2,tc=3;
			long long tmp=1;
			
			if (ta-((p[i].fr==1)+(p[j].fr==1))==1) tmp*=(cnt[r][1]-cnt[l][1]);
						
			if (tb-((p[i].fr==2)+(p[j].fr==2))>(cnt[r][2]-cnt[l][2])) continue;
			if (tb-((p[i].fr==2)+(p[j].fr==2))==1) tmp*=(cnt[r][2]-cnt[l][2]);
			if (tb-((p[i].fr==2)+(p[j].fr==2))==2) tmp*=(cnt[r][2]-cnt[l][2])*(cnt[r][2]-cnt[l][2]-1)/2;
			
			if (tc-((p[i].fr==3)+(p[j].fr==3))>(cnt[r][3]-cnt[l][3])) continue;
			if (tc-((p[i].fr==3)+(p[j].fr==3))==1) tmp*=(cnt[r][3]-cnt[l][3]);
			if (tc-((p[i].fr==3)+(p[j].fr==3))==2) tmp*=(cnt[r][3]-cnt[l][3])*(cnt[r][3]-cnt[l][3]-1)/2;
			if (tc-((p[i].fr==3)+(p[j].fr==3))==3) tmp*=(cnt[r][3]-cnt[l][3])*(cnt[r][3]-cnt[l][3]-1)*(cnt[r][3]-cnt[l][3]-2)/6;
						
			if (ta+tb+tc==6) ans+=tmp;
		}
	}
	
	printf("%I64d\n",ans);
	
	return 0;
}