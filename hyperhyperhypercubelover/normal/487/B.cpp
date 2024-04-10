#include<cstdio>
#include<deque>
#include<algorithm>

int a[111111];
int d[111111];
std::deque<int> max,min,dp,pos;

int main()
{
	int i,j,k,n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d[i]=1e9;
	}
	j=0;
	dp.push_back(0);
	pos.push_back(0);
    for(i=1;i<=n;i++)
	{
        while(!max.empty()&&max.back()<a[i])max.pop_back();
        while(!min.empty()&&min.back()>a[i])min.pop_back();
        max.push_back(a[i]);
        min.push_back(a[i]);
        while(max.front()-min.front()>m)
		{
			if(dp.front()==d[j])
			{
				dp.pop_front();
				pos.pop_front();
			}
			j++;
            if(max.front()==a[j])max.pop_front();
            if(min.front()==a[j])min.pop_front();
		}
		if(i-pos.front()>=l)d[i]=dp.front()+1;
		while(!dp.empty()&&dp.back()>d[i])
		{
			dp.pop_back();
			pos.pop_back();
		}
		dp.push_back(d[i]);
		pos.push_back(i);
	}
	printf("%d",d[n]<=n?d[n]:-1);
}