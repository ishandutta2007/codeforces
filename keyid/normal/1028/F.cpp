#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Point
{
	int x,y;

	Point(){}
	Point(int x,int y):x(x),y(y){}

	void read()
	{
		scanf("%d%d",&x,&y);
	}

	bool operator < (const Point &b) const
	{
		return x!=b.x?x<b.x:y<b.y;
	}

	Point operator + (const Point &b) const
	{
		return Point(x+b.x,y+b.y);
	}
};

map <LL,set<Point>> ms;
map <Point,int> cnt_line,cnt_pair;

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int q;
	scanf("%d",&q);
	int op,cnt=0;
	Point p;
	while (q--)
	{
		scanf("%d",&op);
		p.read();
		if (op==1)
		{
			cnt++;
			LL c=(LL)p.x*p.x+(LL)p.y*p.y;
			int g=__gcd(p.x,p.y);
			Point p2={p.x/g,p.y/g};
			cnt_line[p2]++;
			for (const auto &t:ms[c])
			{
				Point s=t+p;
				int g=__gcd(s.x,s.y);
				s.x/=g;
				s.y/=g;
				cnt_pair[s]++;
			}
			ms[c].insert(p);
		}
		else if (op==2)
		{
			cnt--;
			LL c=(LL)p.x*p.x+(LL)p.y*p.y;
			int g=__gcd(p.x,p.y);
			Point p2={p.x/g,p.y/g};
			cnt_line[p2]--;
			ms[c].erase(p);
			for (const auto &t:ms[c])
			{
				Point s=t+p;
				int g=__gcd(s.x,s.y);
				s.x/=g;
				s.y/=g;
				cnt_pair[s]--;
			}
		}
		else
		{
			int g=__gcd(p.x,p.y);
			p.x/=g;
			p.y/=g;
			printf("%d\n",cnt-cnt_line[p]-2*cnt_pair[p]);
			//printf("%d %d %d\n",cnt,cnt_line[p],cnt_pair[p]);
		}
	}
	return 0;
}