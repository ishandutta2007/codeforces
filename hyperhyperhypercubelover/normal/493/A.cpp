#include<cstdio>
#include<vector>

char h[222];
char a[222];

int hc[222];
int ac[222];

char t[222];
char p[222];

std::vector<std::pair<std::pair<int,int>,int> > r;

int main()
{
	int i,j,k,n;
	scanf("%s%s%d",h,a,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%s%d%s",&j,t,&k,p);
        if(t[0]=='h')
        {
			if(p[0]=='y')hc[k]++;
			else hc[k]+=2;
			if(hc[k]>1)
			{
				r.push_back(std::make_pair(std::make_pair(0,k),j));
                hc[k]=-1e9;
			}
        }
        else
        {
			if(p[0]=='y')ac[k]++;
			else ac[k]+=2;
			if(ac[k]>1)
			{
				r.push_back(std::make_pair(std::make_pair(1,k),j));
                ac[k]=-1e9;
			}
        }
	}
	for(i=0;i<r.size();i++)printf("%s %d %d\n",r[i].first.first?a:h,r[i].first.second,r[i].second);
}