//Author: Kevin5307
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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
char buff[10];
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> vec;
	for(int i=1;i<=n;i++)
		vec.pb(i);
	bool f=0;
	int cnt=0;
	while(sz(vec)>2&&!f)
	{
		if(sz(vec)==3)
			f=1;
		vector<int> vect[4];
		for(int i=0;i<sz(vec);i++)
			vect[i%4].pb(vec[i]);
		int f1=0;
		printf("? %d ",sz(vect[0])+sz(vect[1]));
		for(int i=0;i<2;i++)
			for(auto x:vect[i])
				printf("%d ",x);
		puts("");
		fflush(stdout);
		scanf("%s",buff);
		if(*buff=='N')
			f1=0;
		else	f1=1;
		int f2=0;
		printf("? %d ",sz(vect[0])+sz(vect[2]));
		for(int i=0;i<3;i+=2)
			for(auto x:vect[i])
				printf("%d ",x);
		puts("");
		fflush(stdout);
		scanf("%s",buff);
		if(*buff=='N')
			f2=0;
		else	f2=1;
		vector<int> vecn;
		for(int i=0;i<4;i++)
			if(i!=f1*2+f2)
				for(auto x:vect[i])
					vecn.pb(x);
		if(cnt+2>82)
			exit(3);
		cnt+=2;
		vec=vecn;
	}
	if(sz(vec)==1)
	{
		printf("! %d\n",vec[0]);
		fflush(stdout);
		scanf("%s",buff);
		return 0;
	}
	if(sz(vec)==2)
	{
		printf("! %d\n",vec[0]);
		fflush(stdout);
		scanf("%s",buff);
		if(buff[1]=='(')
		{
			printf("! %d\n",vec[1]);
			fflush(stdout);
			scanf("%s",buff);
		}
		return 0;
	}
	if(cnt+2>82)
		exit(3);
	int ans1=0,ans2=0;
	printf("? 1 %d\n",vec[1]);
	fflush(stdout);
	scanf("%s",buff);
	int f1=(buff[0]!='N');
	printf("? 1 %d\n",vec[0]);
	fflush(stdout);
	scanf("%s",buff);
	int f2=(buff[0]!='N');
	if(f1&&f2)
	{
		ans1=vec[0];
		ans2=vec[1];
	}
	else if(f1)
	{
		ans1=vec[1];
		ans2=vec[2];
	}
	else if(f2)
	{
		ans1=vec[0];
		ans2=vec[2];
	}
	else
	{
		ans1=vec[0];
		ans2=vec[2];
	}
	printf("! %d\n",ans1);
	fflush(stdout);
	scanf("%s",buff);
	if(buff[1]=='(')
	{
		printf("! %d\n",ans2);
		fflush(stdout);
		scanf("%s",buff);
	}
	return 0;
}