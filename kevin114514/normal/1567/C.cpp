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
		string S;
		cin>>S;
		int a=0,b=0;
		for(int i=0;i<S.length();i++)
			if(i%2)
				b=(b<<1)+(b<<3)+S[i]-'0';
			else	a=(a<<1)+(a<<3)+S[i]-'0';
		cout<<1ll*(a+1)*(b+1)-2<<endl;
	}
	return 0;
}