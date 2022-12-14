#include <stdio.h>
#include <deque>
#define SIZE 400

int count[310][100010];
std::deque<int> deq[310],temp;

int func1(int t)
{
	int ans = -1;
	for(int i=0;i<250;i++)
	{
		int L = i*SIZE+1;
		int R = (i+1)*SIZE;
		if(L<=t&&t<=R)
		{
			for(int j=L;j<t;j++)
			{
				temp.push_back(deq[i].front());
				deq[i].pop_front();
			}
			count[i][deq[i].front()]--;
			ans = deq[i].front();
			deq[i].pop_front();
			while(!temp.empty())
			{
				deq[i].push_front(temp.back());
				temp.pop_back();
			}
			return ans;
		}
	}
}

void func2(int s, int val)
{
	for(int i=0;i<250;i++)
	{
		int L = i*SIZE+1;
		int R = (i+1)*SIZE;
		if(L<=s&&s<=R)
		{
			for(int j=L;j<s;j++)
			{
				temp.push_back(deq[i].front());
				deq[i].pop_front();
			}
			count[i][val]++;
			deq[i].push_front(val);
			while(!temp.empty())
			{
				deq[i].push_front(temp.back());
				temp.pop_back();
			}
			return;
		}
	}
}

void func(int s, int t)
{
	int val = func1(t);
	func2(s,val);
	for(int i=0;i<250;i++)
	{
		int L = i*SIZE+1;
		int R = (i+1)*SIZE;
		if(s<L&&L<=t)
		{
			count[i][deq[i-1].back()]++;
			count[i-1][deq[i-1].back()]--;
			deq[i].push_front(deq[i-1].back());
			deq[i-1].pop_back();
		}
	}
}

int getAns(int s, int t, int val)
{
	int ans = 0;
	for(int i=0;i<250;i++)
	{
		int L = i*SIZE+1;
		int R = (i+1)*SIZE;
		if(s<=L&&R<=t) ans += count[i][val];
		else if(t<L);
		else if(R<s);
		else
		{
			for(int j=L;j<=R&&(!deq[i].empty());j++)
			{
				if(s<=j&&j<=t&&deq[i].front()==val) ans++;
				temp.push_back(deq[i].front());
				deq[i].pop_front();
			}
			while(!temp.empty())
			{
				deq[i].push_front(temp.back());
				temp.pop_back();
			}
		}
	}
	return ans;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		deq[(i-1)/SIZE].push_back(b);
		count[(i-1)/SIZE][b]++;
	}
	
	int b;
	scanf("%d",&b);
	int ans = 0;
	for(int i=1;i<=b;i++)
	{
		int d;
		scanf("%d",&d);
		if(d==1)
		{
			int e,f;
			scanf("%d%d",&e,&f);
			e = ((e+ans-1)%a+1);
			f = ((f+ans-1)%a+1);
			if(e>f)
			{
				int t = e;
				e = f;
				f = t;
			}
			func(e,f);
		}
		else
		{
			int e,f,g;
			scanf("%d%d%d",&e,&f,&g);
			e = ((e+ans-1)%a+1);
			f = ((f+ans-1)%a+1);
			g = ((g+ans-1)%a+1);
			if(e>f)
			{
				int t = e;
				e = f;
				f = t;
			}
			ans = getAns(e,f,g);
			printf("%d\n",ans);
		}
	}
}