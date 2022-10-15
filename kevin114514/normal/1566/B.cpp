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
		string s;
		cin>>s;
		int cnt0=0,lst=-1;
		bool x=0;
		for(int i=0;i<s.length();i++)
			if(s[i]-'0'!=lst)
			{
				lst=s[i]-'0';
				if(!lst)
					cnt0++;
				x|=lst;
			}
		cout<<min(cnt0,1+x)<<endl;
	}
	return 0;
}