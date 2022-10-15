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
int one[]   ={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,1000000001};
int eleven[]={1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111,1111111111};
int getmax(set<int> s)
{
	set<int>::iterator it=s.end();
	it--;
	return *it;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		set<int> s;
		int cur=0;
		int m=0;
		while(n>=one[m++]);
		m--;
//		cout<<m<<endl;
		for(int i=0;i<m;i++)
		{
//			cout<<i<<" "<<cur<<endl;
//			for(set<int>::iterator it=s.begin();it!=s.end();it++)
//				cout<<*it<<" ";
//			puts("");
			if(sz(s)==k)
			{
				for(int j=i;j<m;j++)
					for(set<int>::iterator it=s.begin();it!=s.end();it++)
						if(cur+*it*one[m-j-1]+(i==m-1?0:eleven[m-j-2]*getmax(s))>=n)
						{
							cur+=*it*one[m-j-1];
							break;
						}
				break;
			}
			if(sz(s)&&cur>n/one[m-i]*one[m-i])
			{
				s.insert(0);
				for(int j=i;j<m;j++)
					for(set<int>::iterator it=s.begin();it!=s.end();it++)
						if(cur+*it*one[m-j-1]+(i==m-1?0:eleven[m-j-2]*getmax(s))>=n)
						{
							cur+=*it*one[m-j-1];
							break;
						}
				break;
			}
			s.insert(n/one[m-i-1]%10);
			cur+=(n/one[m-i-1]%10)*one[m-i-1];
			if(sz(s)==k&&cur+getmax(s)*(i==m-1?0:eleven[m-i-2])<n)
			{
//				puts("lol");
				s.erase(n/one[m-i-1]%10);
				s.insert(n/one[m-i-1]%10+1);
				cur+=one[m-i-1];
//				puts("lmao");
			}
		}
		cout<<cur<<endl;
	}
	return 0;
}