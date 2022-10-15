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
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int x=max(max(a,b),c);
		int y=min(min(a,b),c);
		if(a+b+c-3<d)
			puts("NO");
		else
		{
			if(x>d)
			{
				if(x-d<=a+b+c-x+1)
					puts("YES");
				else	puts("NO");
			}
			else	puts("YES");
		}
	}
	return 0;
}