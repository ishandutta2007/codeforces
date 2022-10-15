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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		multiset<int> st;
		multiset<int> nst;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if(x)
				st.insert(x);
			else	cnt++;
		}
		while(sz(st)>1)
		{
//			for(auto x:st)
//				cout<<x<<" ";
//			puts("");
//			system("pause");
			int ncnt=cnt;
			nst.clear();
			int lst=-1;
			for(auto x:st)
			{
				if(lst==-1)
				{
					if(cnt)
					{
						cnt--;
						ncnt--;
						nst.insert(x);
					}
					lst=x;
					continue;
				}
				if(lst!=x)
					nst.insert(x-lst);
				else	ncnt++;
				lst=x;
			}
			cnt=ncnt;
			st=nst;
		}
		cout<<(*st.begin())<<endl;
	}
	return 0;
}