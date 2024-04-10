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
ll x[100100];
int prv[40020];
int ans[100100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			sum+=x[i];
		}
		if(n%2==0)
		{
			for(int i=0;i<n;i+=2)
				cout<<x[i+1]<<" "<<-x[i]<<" ";
			puts("");
		}
		else if(n<=20000)
		{
			for(int i=0;i<n;i++) if(x[i]!=sum)
			{
				for(int j=0;j<n;j++)
					if(i==j)
						cout<<(x[i]-sum)<<" ";
					else	cout<<x[i]<<" ";
				puts("");
				break;
			}
		}
		else
		{
			memset(prv,-1,sizeof(prv));
			for(int i=0;i<n;i++) if(prv[20020+x[i]]!=-1)
			{
				int lst=prv[20020+x[i]];
				swap(x[i],x[n-1]);
				swap(x[lst],x[n-2]);
				for(int j=0;j<n-3;j+=2)
				{
					ans[j]=x[j+1];
					ans[j+1]=-x[j];
				}
				if(x[n-3]==-1)
				{
					ans[n-3]=x[n-1];
					ans[n-2]=-1;
					ans[n-1]=2;
				}
				else
				{
					ans[n-3]=x[n-1];
					ans[n-2]=1;
					ans[n-1]=-1-x[n-3];
				}
				swap(ans[lst],ans[n-2]);
				swap(ans[i],ans[n-1]);
				for(int i=0;i<n;i++)
					cout<<ans[i]<<" ";
				puts("");
				break;
			}
			else	prv[20020+x[i]]=i;
		}
	}
	return 0;
}