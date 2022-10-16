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
ll b[100100];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>b[i];
	if(n<3)
		die("0");
	int ans=1e9;
	for(int x=-1;x<=1;x++)
		for(int y=-1;y<=1;y++)
		{
			ll diff=(b[1]+y)-(b[0]+x);
			ll number=b[1]+y;
			bool flag=true;
			int cnt=0;
			for(int j=2;j<n;j++)
			{
				number+=diff;
				if(abs(number-b[j])>1)
				{
					flag=0;
					break;
				}
				cnt+=abs(number-b[j]);
			}
			if(flag)
				ans=min(ans,cnt+abs(x)+abs(y));
		}
	if(ans==1e9)
		die("-1");
	cout<<ans<<endl;
	return 0;
}