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
bool chk[100100];
int main()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<n-2;i++)
		chk[i]=s.substr(i,3)=="abc";
	int sum=0;
	for(int i=0;i<n-2;i++)
		sum+=chk[i];
	while(k--)
	{
		int p;
		string t;
		cin>>p>>t;
		s[p-1]=t[0];
		for(int i=max(0,p-3);i<min(n-2,p);i++)
		{
			sum-=chk[i];
			chk[i]=s.substr(i,3)=="abc";
			sum+=chk[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}