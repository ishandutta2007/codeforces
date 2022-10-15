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
int bit[100100];
bool mk[100100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			mk[i]=bit[i]=0;
		string s,t;
		cin>>s>>t;
		for(int i=0;i<n;i++)
			bit[i]|=((1<<(s[i]-'0'))|(1<<(t[i]-'0')));
		int ans=0;
		for(int i=0;i<n;i++)
		{
//			cout<<bit[i]<<endl;
			if(bit[i]==3)
				ans+=2;
			if(bit[i]==1)
			{
				if((i>0&&bit[i-1]==2)&&!mk[i-1])
				{
					ans+=2;
				}
				else if(i<n-1&&(i<n-1&&bit[i+1]==2))
				{
					ans+=2;
					mk[i+1]=1;
					
				}
				else	ans+=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}