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
ll psum[1001000];
ll num[1001000];
int n;
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			int y;
			cin>>y;
			psum[n]=(n?psum[n-1]:0)+y;
			num[n++]=y;
		}
		else
		{
			double l=0,r=num[n-1];
			for(int i=0;i<100;i++)
			{
				double mid=(l+r)/2;
//				cout<<mid<<endl;
				int p=lower_bound(num,num+n,(int)(mid)+1)-num;
//				cout<<p<<endl;
				if(!p)
					l=mid;
				else if((psum[p-1]+num[n-1])*1.0/(p+1)<=mid)
					r=mid;
				else	l=mid;
			}
			printf("%.12lf\n",num[n-1]-l);
		}
	}
	return 0;
}