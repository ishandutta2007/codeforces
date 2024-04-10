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
int a[200200];
bool b[200200];
int main()
{
	int increase=-1,decrease=1e9;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(!(a[i]>increase||a[i]<decrease))
			die("NO");
		if((a[i]>increase)^(a[i]<decrease))
		{
			if(a[i]>increase)
				b[i]=0;
			else	b[i]=1;
		}
		else if(a[i+1]>a[i])
			b[i]=0;
		else	b[i]=1;
		if(b[i])
			decrease=a[i];
		else	increase=a[i];
	}
	puts("YES");
	for(int i=0;i<n;i++)
		cout<<b[i]<<" ";
	return 0;
}