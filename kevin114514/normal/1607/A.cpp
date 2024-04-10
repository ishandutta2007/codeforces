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
int pos[2566];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,t;
		cin>>s>>t;
		for(int i=0;i<sz(s);i++)
			pos[s[i]]=i;
		int cnt=0;
		for(int i=0;i<sz(t)-1;i++)
			cnt+=abs(pos[t[i]]-pos[t[i+1]]);
		cout<<cnt<<endl;
	}
	return 0;
}