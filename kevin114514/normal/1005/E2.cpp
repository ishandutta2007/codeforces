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
int number[200200];
int psum[200200];
int n,m;
int BIT[600600];
const int thres=600000;
void upd(int pos)
{
	while(pos<=thres)
	{
//		cout<<pos<<endl;
		BIT[pos]++;
		pos+=(pos&(-pos));
	}
}
int query(int pos)
{
	int ans=0;
	while(pos)
	{
//		cout<<"# "<<pos<<endl;
		ans+=BIT[pos];
		pos-=(pos&(-pos));
	}
	return ans;
}
ll calc(int median)
{
	memset(BIT,0,sizeof(BIT));
	for(int i=1;i<=n;i++)
		psum[i]=psum[i-1]+(bool)(number[i]<median);
	ll res=0;
	for(int i=n;i;i--)
	{
//		cout<<psum[i]<<" ";
		upd(2*psum[i]-i+n+1);
		res+=query(2*psum[i-1]-i+n+1);
	}
//	puts("");
//	cout<<median<<" "<<res<<endl;
	return res;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>number[i];
	cout<<calc(m)-calc(m+1)<<endl;
	return 0;
}