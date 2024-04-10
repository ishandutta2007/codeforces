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
int det[100100][5];
priority_queue<pii> harm[5];
int xxx[5];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>det[i][j];
	int l=0,r=0;
//	for(int i=0;i<m;i++)
//		harm[i].push(mp(det[0][i],0));
	int ans=0;
	while(l<n)
	{
		for(int i=0;i<m;i++)
			while(!harm[i].empty()&&harm[i].top().second<l)
				harm[i].pop();
		while(r<n)
		{
			int sum=0;
			for(int i=0;i<m;i++)
				if(!harm[i].empty())
				{
//					cout<<"# "<<i<<" "<<harm[i].top().first<<endl;
					sum+=max(harm[i].top().first,det[r][i]);
				}
				else	sum+=det[r][i];
//			cout<<l<<" "<<r<<" "<<sum<<endl;
			if(sum>k)
				break;
			for(int i=0;i<m;i++)
			{
//				cout<<"insert:"<<i<<" "<<det[r][i]<<endl;
				harm[i].push(mp(det[r][i],r));
			}
			r++;
		}
//		cout<<l<<" "<<r<<endl;
		if(r-l>ans)
		{
			ans=r-l;
			for(int i=0;i<m;i++)
				xxx[i]=harm[i].top().first;
		}
		l++;
		r=max(r,l);
	}
	for(int i=0;i<m;i++)
		cout<<xxx[i]<<" ";
	return 0;
}