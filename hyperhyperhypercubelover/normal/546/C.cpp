#include<cstdio>
#include<deque>

std::deque<int> a,b;

int main()
{
    int i,n,t;
    scanf("%*d");
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		scanf("%d",&t);
        a.push_back(t);
	}
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		scanf("%d",&t);
        b.push_back(t);
	}
	for(i=0;!a.empty()&&!b.empty()&&i<1e7;i++)
	{
        if(a.front()>b.front())
		{
            a.push_back(b.front());
            a.push_back(a.front());
		}
		else
		{
            b.push_back(a.front());
            b.push_back(b.front());
		}
            a.pop_front();
            b.pop_front();
	}
	if(i<1e7)printf("%d %d\n",i,a.empty()+1);
	else puts("-1");
}