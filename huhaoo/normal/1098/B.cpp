/****************************************************************
	File name: D.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 1/6/2019, 12:51:20 AM
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define N 300010
int n,m,ans;
char s[N],pr[10]={' ','A','G','C','T'},out[N];
int get(int x,int y)
{
	return s[(x-1)*m+y];
}
int main()
{
	n=read();
	m=read();
	fr(i,1,n*m)
	{
		s[i]=getchar();
		while(s[i]!='A'&&s[i]!='G'&&s[i]!='C'&&s[i]!='T')
			s[i]=getchar();
		if(s[i]=='A')
			s[i]=1;
		else if(s[i]=='G')
			s[i]=2;
		else if(s[i]=='C')
			s[i]=3;
		else
			s[i]=4;
	}
	fr(i,1,4)
		fr(j,i+1,4)
			fr(k,1,4)
				fr(o,k+1,4)
					if(i!=k&&i!=o&&j!=k&&j!=o)
					{
						int t=0;
						fr(l,1,n)
						{
							int s1=0,s2=0;
							if(l&1)
							{
								fr(p,1,m)
									if(p&1)
									{
										s1+=get(l,p)==i;
										s2+=get(l,p)==j;
									}
									else
									{
										s1+=get(l,p)==j;
										s2+=get(l,p)==i;
									}
							}
							else
							{
								fr(p,1,m)
									if(p&1)
									{
										s1+=get(l,p)==k;
										s2+=get(l,p)==o;
									}
									else
									{
										s1+=get(l,p)==o;
										s2+=get(l,p)==k;
									}
							}
							t+=max(s1,s2);
						}
						ans=max(ans,t);
						t=0;
						fr(l,1,m)
						{
							int s1=0,s2=0;
							if(l&1)
							{
								fr(p,1,n)
									if(p&1)
									{
										s1+=get(p,l)==i;
										s2+=get(p,l)==j;
									}
									else
									{
										s1+=get(p,l)==j;
										s2+=get(p,l)==i;
									}
							}
							else
							{
								fr(p,1,n)
									if(p&1)
									{
										s1+=get(p,l)==k;
										s2+=get(p,l)==o;
									}
									else
									{
										s1+=get(p,l)==o;
										s2+=get(p,l)==k;
									}
							}
							t+=max(s1,s2);
						}
						ans=max(ans,t);
					}
//	printf("%d\n",ans);
/*	fr(i,1,n)
	{
		fr(j,1,m)
			putchar(pr[get(i,j)]);
		putchar(10);
	}*/
	fr(i,1,4)
		fr(j,i+1,4)
			fr(k,1,4)
				fr(o,k+1,4)
					if(i!=k&&i!=o&&j!=k&&j!=o)
					{
						int t=0;
						fr(l,1,n)
						{
							int s1=0,s2=0;
							if(l&1)
							{
								fr(p,1,m)
									if(p&1)
									{
										s1+=get(l,p)==i;
										s2+=get(l,p)==j;
									}
									else
									{
										s1+=get(l,p)==j;
										s2+=get(l,p)==i;
									}
							}
							else
							{
								fr(p,1,m)
									if(p&1)
									{
										s1+=get(l,p)==k;
										s2+=get(l,p)==o;
									}
									else
									{
										s1+=get(l,p)==o;
										s2+=get(l,p)==k;
									}
							}
							t+=max(s1,s2);
						}
						if(ans==t)
						{
							fr(l,1,n)
							{
								int s1=0,s2=0;
								if(l&1)
								{
									fr(p,1,m)
										if(p&1)
										{
											s1+=get(l,p)==i;
											s2+=get(l,p)==j;
//								printf("%d %d %d\n",s1,s2,get(l,p));
										}
										else
										{
											s1+=get(l,p)==j;
											s2+=get(l,p)==i;
//								printf("%d %d %d\n",s1,s2,get(l,p));
										}
								}
								else
								{
									fr(p,1,m)
										if(p&1)
										{
											s1+=get(l,p)==k;
											s2+=get(l,p)==o;
//								printf("%d %d %d\n",s1,s2,get(l,p));
										}
										else
										{
											s1+=get(l,p)==o;
											s2+=get(l,p)==k;
//								printf("%d %d %d\n",s1,s2,get(l,p));
										}
								}
						//		printf("%d %d\n",s1,s2);
								if(s1>s2)
									fr(p,1,m)
									{
										if(l&1)
										{
											if(p&1)
												putchar(pr[i]);
											else
												putchar(pr[j]);
										}
										else
										{
											if(p&1)
												putchar(pr[k]);
											else
												putchar(pr[o]);
										}
									}
								else
									fr(p,1,m)
									{
										if(l&1)
										{
											if(p&1)
												putchar(pr[j]);
											else
												putchar(pr[i]);
										}
										else
										{
											if(p&1)
												putchar(pr[o]);
											else
												putchar(pr[k]);
										}
									}
//								printf("%d %d %d %d\n",i,j,k,o);
								putchar('\n');
							}
							return 0;
						}
						t=0;
						fr(l,1,m)
						{
							int s1=0,s2=0;
							if(l&1)
							{
								fr(p,1,n)
									if(p&1)
									{
										s1+=get(p,l)==i;
										s2+=get(p,l)==j;
									}
									else
									{
										s1+=get(p,l)==j;
										s2+=get(p,l)==i;
									}
							}
							else
							{
								fr(p,1,n)
									if(p&1)
									{
										s1+=get(p,l)==k;
										s2+=get(p,l)==o;
									}
									else
									{
										s1+=get(p,l)==o;
										s2+=get(p,l)==k;
									}
							}
							t+=max(s1,s2);
						}
						if(t==ans)
						{
							fr(l,1,m)
							{
								int s1=0,s2=0;
								if(l&1)
								{
									fr(p,1,n)
										if(p&1)
										{
											s1+=get(p,l)==i;
											s2+=get(p,l)==j;
										}
										else
										{
											s1+=get(p,l)==j;
											s2+=get(p,l)==i;
										}
								}
								else
								{
									fr(p,1,n)
										if(p&1)
										{
											s1+=get(p,l)==k;
											s2+=get(p,l)==o;
										}
										else
										{
											s1+=get(p,l)==o;
											s2+=get(p,l)==k;
										}
								}
								if(s1>s2)
									fr(p,1,n)
									{
										int _;
										if(l&1)
										{
											if(p&1)
												_=pr[i];
											else
												_=pr[j];
										}
										else
										{
											if(p&1)
												_=pr[k];
											else
												_=pr[o];
										}
										out[(p-1)*m+l]=_;
									}
								else
									fr(p,1,n)
									{
										int _;
										if(l&1)
										{
											if(p&1)
												_=pr[j];
											else
												_=pr[i];
										}
										else
										{
											if(p&1)
												_=pr[o];
											else
												_=pr[k];
										}
										out[(p-1)*m+l]=_;
									}
							}
							fr(k,1,n*m)
							{
								putchar(out[k]);
								if(k%m==0)
									putchar(10);
							}
							return 0;
						}
					}
	return 0;
}