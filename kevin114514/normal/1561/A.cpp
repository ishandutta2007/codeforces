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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.pb(x);
		}
		vector<int> u=v;
		srt(u);
		int cnt=0;
		while(u!=v)
		{
			for(int i=cnt%2;i<n-1;i+=2)
				if(v[i]>v[i+1])
					swap(v[i],v[i+1]);
			cnt++;
//			cout<<cnt<<endl;
//			for(int i=0;i<n;i++)
//				cout<<v[i]<<" ";
//			puts("");
		}
		cout<<cnt<<endl;
	}
	return 0;
}