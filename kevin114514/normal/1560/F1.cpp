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
#define int ll
void die(string S){puts(S.c_str());exit(0);}
int one[]={1,11,111,1111,11111,111111,1111111,11111111,111111111,11111111111};
int ten[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,10000000000};
int calc(int x)
{
	int ans=1e9;
	int num=0;
	for(;ten[num]<=x;num++);
	for(int i=0;i<10;i++)
		for(int j=i+1;j<10;j++)
		{
			int tmp=0;
			for(int k=0;k<num;k++)
				if(x<=tmp+i*ten[num-k-1]+j*(k==num-1?0:one[num-k-2]))
					tmp+=i*ten[num-k-1];
				else	tmp+=j*ten[num-k-1];
//			cout<<i<<" "<<j<<" "<<tmp<<endl;
			if(tmp>=x)
				ans=min(ans,tmp);
		}
	for(int i=0;i<10;i++)
		if(i*one[num-1]>=x)
			ans=min(ans,i*one[num-1]);
	return ans;
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,k;
		cin>>x>>k;
		if(x==1e9)
		{
			if(k==2)
				cout<<x<<endl;
			else	puts("1111111111");
			continue;
		}
		if(k==1)
		{
			bool flag=true;
			for(int i=0;i<9&&flag;i++)
				for(int j=1;j<=9&&flag;j++)
					if(one[i]*j>=x)
					{
						cout<<one[i]*j<<endl;
						flag=0;
					}
			continue;
		}
		cout<<calc(x)<<endl;
	}
	return 0;
}