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
void die(string S){puts(S.c_str());exit(0);}
vector<int> v;
int ans[110];
int sum(vector<int> u)
{
	int ret=0;
	for(int i=0;i<sz(u);i++)
		ret+=u[i];
	return ret;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		v.clear();
		memset(ans,0,sizeof(ans));
		string S;
		int K;
		cin>>S>>K;
		for(int i=0;i<S.length();i++)
			v.pb(S[i]-'0');
		while(sum(v)<K)
		{
			bool flag=false;
			for(int i=sz(v)-2;i;i--)
				if(v[i])
				{
					v[i+1]+=10;
					v[i]-=1;
					flag=1;
					break;
				}
			if(!flag)
			{
				v[1]+=10;
				v[0]--;
				while(sz(v)&&!v[0])
					v.erase(v.begin());
			}
		}
		int x=0;
		for(int i=0;i<sz(v);i++)
		{
			for(int j=0;j<K;j++)
				ans[j]*=10;
			int tmp=x;
			int choose=(x!=K?v[i]/(K-x):0);
			choose=min(choose,9);
			int Tmp=(x!=K?v[i]%(K-x):0);
			if(choose==9)
				Tmp=0;
			while(x<K&&v[i])
			{
				ans[x]+=min(v[i],choose+(bool)(Tmp));
				v[i]-=min(v[i],choose+(bool)(Tmp));
				if(Tmp)
					Tmp--;
				x++;
			}
			if(x==K)
			{
				for(int j=0;j<tmp;j++)
				{
					ans[j]+=min(v[i],9);
					v[i]-=min(v[i],9);
				}
			}
		}
		for(int i=0;i<K;i++)
			cout<<ans[i]<<" ";
		puts("");
	}
	return 0;
}