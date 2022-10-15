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
map<long double,int> Mp;
int x[200100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Mp.clear();
		int n;
		long double k=0.0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			k+=x[i];
		}
		k/=n;
		ll flag=0;
		for(int i=0;i<n;i++)
		{
			flag+=Mp[k+k-x[i]];
			Mp[x[i]]++;
		}
		cout<<flag<<endl;
	}
	return 0;
}