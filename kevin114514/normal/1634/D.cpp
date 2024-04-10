#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int guess(int i,int j,int k)
{
	printf("? %d %d %d\n",i,j,k);
	fflush(stdout);
	int x;
	cin>>x;
	return x;
}
void answer(int i,int j)
{
	printf("! %d %d\n",i,j);
	fflush(stdout);
	return ;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int del=-1;
		int ind=0;
		set<int> t;
		for(int i=3;i<=n;i++)
		{
			int x=guess(1,2,i);
			if(x>del)
			{
				del=x;
				ind=i;
			}
			t.insert(x);
		}
		if(sz(t)==1)
		{
			int tar=*t.begin();
			{
				int index=0;
				int delta=-1;
				for(int i=3;i<n;i++)
				{
					int y=guess(1,i,i+1);
					if(y>delta)
					{
						index=i;
						delta=y;
					}
				}
				if(tar>=delta)
					answer(1,2);
				else	answer(index+1,index);
			}
			continue;
		}
		set<int> s;
		del=-1;
		int ind2=ind;
		ind=0;
		for(int i=2;i<=n;i++) if(i!=ind2)
		{
			int x=guess(1,ind2,i);
			if(x>del)
			{
				del=x;
				ind=i;
			}
			s.insert(x);
		}
		if(sz(s)==1)
			answer(1,ind2);
		else	answer(ind,ind2);
	}
	return 0;
}