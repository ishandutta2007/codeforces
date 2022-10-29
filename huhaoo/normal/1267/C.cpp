/***************************************************************
	File name: C.cpp
	Author: huhao
	Create time: Mon 19 Apr 2021 10:26:14 AM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define i64 long long
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
#include<vector>
const int N=2010;
int n;
void nosol(bool f=false){ if(f) return ; printf("-1\n"); exit(0); }
std::vector<std::vector<int> > solve(std::vector<int> a)
{
	if(a.empty()) return {};
	int n=a.size(),m=0; std::vector<std::vector<int> > ans;
	fr(i,0,n-1) m+=a[i];
	nosol(m%2==0); m/=2; nosol(m>=n-1);
	if(m==n-1)
	{
		while(m--)
		{
			int x=0,y=0;
			fr(i,0,n-1) if(a[i]==1){ a[i]--; x=i+1; break; }
			fr(i,0,n-1) if(a[i]>(m?1:0)){ a[i]--; y=i+1; break; }
			nosol(x&&y); ans.push_back({2,x,y});
		}
		return ans;
	}
	int c=m-n+1; nosol(c<=(n-1)/2);
//	fr(i,0,n-1) printf("%d%c",a[i],i==n-1?'\n':' ');
	int flag=1;
	fr(i,0,n-1) if(a[i]&1) flag=0;
	if(flag)
	{
		while((c--)>1)
		{
			int x=0,y=0,z=0;
			fr(i,0,n-1)
			{
				if(a[i]==2)
				{
					if(!x) x=i+1;
					else if(!y) y=i+1;
					else continue;
					a[i]-=2;
				}
			}
			fr(i,0,n-1) if(a[i]>=4&&!z){ z=i+1; a[i]-=2; }
//			printf("%d  %d %d %d\n",c,x,y,z);
			nosol(x&&y&&z&&x); ans.push_back({4,x,y,z,x});
		}
		std::vector<int> Ans;
		fr(i,0,n-1) if(a[i]) Ans.push_back(i+1);
		nosol(Ans.size()==0||Ans.size()>=3);
		if(!Ans.empty()){ Ans.push_back(*Ans.begin()); Ans.insert(Ans.begin(),Ans.size()); ans.push_back(Ans); }
		return ans;
	}
	int o=0,l=0;
	fr(i,0,n-1)
	{
		if(a[i]&1) o++;
		if(a[i]==1) l++;
	}
	nosol(c<=(n-1-std::max(o/2,l))/2);
	static int id[N],t;
	if(l+l<=o)
	{
		while(l)
		{
			l--; o-=2;
			int x=0,y=0; t++;
			fr(i,0,n-1)
			{
				if(a[i]==1){ if(!x){ x=i+1; a[i]--; id[i]=t; } }
				else if(a[i]&1){ if(!y){ y=i+1; a[i]--; id[i]=t; } }
			}
			ans.push_back({2,x,y});
		}
		while(o)
		{
			o-=2;
			int x=0,y=0; t++;
			fr(i,0,n-1) if(a[i]&1)
			{
				if(!x) x=i+1;
				else if(!y) y=i+1;
				else continue;
				id[i]=t; a[i]--;
			}
			ans.push_back({2,x,y});
		}
	}
	else
	{
		while(l!=o)
		{
			l--; o-=2;
			int x=0,y=0; t++;
			fr(i,0,n-1)
			{
				if(a[i]==1){ if(!x){ x=i+1; a[i]--; id[i]=t; } }
				else if(a[i]&1){ if(!y){ y=i+1; a[i]--; id[i]=t; } }
			}
			ans.push_back({2,x,y});
		}
//		fr(i,0,n-1) printf("%d%c",a[i],i==n-1?'\n':' ');
		while(l)
		{
			l-=2; o-=2;
			int x=0,y=0,z=0,q=0;
			fr(i,0,n-1)
			{
				if(a[i]==1)
				{
					if(!x) x=i+1;
					else if(!y) y=i+1;
					else continue;
					a[i]--;
				}
				else if(a[i]%2==0&&a[i]>=4)
				{
					if(!z) z=i+1;
					else continue;
					a[i]-=2; q=id[i];
				}
			}
			if(!q) q=++t;
			id[x-1]=id[y-1]=id[z-1]=q;
//			printf("%d %d %d\n",x,y,z);
			nosol(x&&y&&z); ans.push_back({3,x,z,y});
		}
//		fr(i,0,n-1) printf("%d%c",a[i],i==n-1?'\n':' ');
	}
//	fr(i,0,n-1) printf("%d%c",id[i],i==n-1?'\n':' ');
	fr(i,0,n-1) if(!id[i]) id[i]=++t;
//	fr(i,0,n-1) printf("%d%c",id[i],i==n-1?'\n':' ');
	std::vector<int> A(t);
	fr(i,0,n-1) A[id[i]-1]+=a[i];
	auto _ans=solve(A);
//	printf("%d\n",(int)_ans.size());
//	for(auto i:_ans){ for(auto j:i) printf("%d ",j); putchar(10); }
	for(auto q:_ans)
	{
		std::vector<int> Ans={q[0]};
		fr(i,1,q[0]-1)
		{
			int x=0;
			fr(j,0,n-1) if(a[j]&&id[j]==q[i]){ x=j+1; a[j]-=2; break; }
			nosol(x); Ans.push_back(x);
		}
		Ans.push_back(Ans[1]); ans.push_back(Ans);
	}
	return ans;
}
int main()
{
	std::vector<int> a;
	n=read();
	fr(i,1,n) a.push_back(read());
	auto ans=solve(a);
	printf("%d\n",(int)ans.size());
	for(auto i:ans){ for(auto j:i) printf("%d ",j); putchar(10); }
	return 0;
}