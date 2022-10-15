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
void die(string S){puts(S.c_str());exit(0);}
int a[200200];
map<int,bool> Mp;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int c1=0,c2=0,c3=0,c4=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>=0)
				c1++;
			if(a[i]<=0)
				c2++;
			if(a[i]>0)
				c3++;
			if(a[i]<0)
				c4++;
		}
		if(c3+c4<=20)
		{
			vector<int> vec;
			vec.pb(0);
			for(int i=1;i<=n;i++)
				if(a[i]!=0)
					vec.pb(a[i]);
			for(int i=0;i<min(3,c1-c3);i++)
				vec.pb(0);
			n=sz(vec)-1;
			Mp.clear();
			for(int i=1;i<=n;i++)
				Mp[vec[i]]=1;
			bool ans=1;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						ans&=Mp[vec[i]+vec[j]+vec[k]];
			if(ans)
				puts("Yes");
			else	puts("No");
		}
		else if(c1>=3&&c3>=2)
			puts("No");
		else if(c2>=3&&c4>=2)
			puts("No");
		else	puts("Yes");
	}
	return 0;
}