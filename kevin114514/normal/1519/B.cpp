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
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(x*y==z+1)
			puts("YES");
		else	puts("NO");
	}
	return 0;
}