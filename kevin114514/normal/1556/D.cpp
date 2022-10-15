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
ll sum[10100];
ll x[10100];
ll getand(int i,int j)
{
	printf("and %d %d\n",i,j);
	fflush(stdout);
	ll ret;
	cin>>ret;
	return ret;
}
ll getor(int i,int j)
{
	printf("or %d %d\n",i,j);
	fflush(stdout);
	ll ret;
	cin>>ret;
	return ret;
}
void generate(int n)
{
	ll S=0; 
	for(int i=1;i<n;i++)
	{
		sum[i]=(getand(i,i+1)+getor(i,i+1));
		S+=sum[i];
	}
	sum[n]=(getand(n,1)+getor(n,1));
	S+=sum[n];
//	cout<<S<<endl;
	S/=2;
	x[n]=S;
	for(int i=1;i<n;i+=2)
		x[n]-=sum[i];
//	cout<<x[n]<<endl;
	for(int i=n-1;i;i--)
		x[i]=sum[i]-x[i+1];
}
int n,k;
int main()
{
	cin>>n>>k;
	if(n%2)
	{
		generate(n);
//		for(int i=1;i<=n;i++)
//			cout<<x[i]<<" ";
//		puts("");
		sort(x+1,x+n+1);
		printf("finish %d\n",x[k]);
		exit(0);
	}
	else
	{
		generate(n-1);
		x[n]=(getand(n-1,n)+getor(n-1,n))-x[n-1];
//		for(int i=1;i<=n;i++)
//			cout<<x[i]<<" ";
//		puts("");
		sort(x+1,x+n+1);
		printf("finish %d\n",x[k]);
		exit(0);
	}
	return 0;
}
/*
7 6
0
7
4
6
0
6
2
3
1
7
4
5
0
5
*/