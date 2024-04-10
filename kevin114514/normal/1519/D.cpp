#include<bits/stdc++.h>
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
void die(string S){puts(S.c_str());exit(0);}
ll a[5050],b[5050];
ll rev[5050][5050];
ll pres[5050];
ll sufs[5050];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
		pres[i+1]=pres[i]+a[i]*b[i];
	for(int i=n-1;i>=0;i--)
		sufs[i]=sufs[i+1]+a[i]*b[i];
	for(int i=0;i<n;i++)
		rev[i][i]=a[i]*b[i];
	ll ans=pres[n];
	for(int l=2;l<=n;l++)
		for(int i=0;i<=n-l;i++)
		{
			int j=i+l-1;
			rev[i][j]=rev[i+1][j-1]+a[i]*b[j]+a[j]*b[i];
		}
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			ans=max(ans,rev[i][j]+pres[i]+sufs[j+1]);
	cout<<ans<<endl;
	return 0;
}
/*
50
14 69 33 38 83 65 21 66 89 3 93 60 31 16 61 20 42 64 13 1 50 50 74 58 67 61 52 22 69 68 18 33 28 59 4 8 96 32 84 85 87 87 61 89 2 47 15 64 88 18
58 100 38 69 55 7 52 29 85 72 71 51 69 46 89 26 19 74 96 43 38 64 47 44 28 1 83 62 43 68 4 49 33 20 93 60 98 44 19 90 29 99 91 87 59 80 60 32 31 92
*/