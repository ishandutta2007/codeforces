#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=20000;
char s[N];
int n;
bool check(int X,int Y)
{
	int x=0,y=0;
	for (int i=0;i<n;i++)
	{
		int X1=x,Y1=y;
		if (s[i]=='R') x++;
    	if (s[i]=='L') x--;
        if (s[i]=='U') y++;
	    if (s[i]=='D') y--;
	    if (x==X&&y==Y)
	    {
	    	x=X1,y=Y1;
	    }
	}
	if (x==0&&y==0) return 1;
	else return 0;
}
int main()
{
	ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while (T--)
    {
    	cin>>s;
    	n=strlen(s);
    	int x=0,y=0,xx=0,yy=0;
    	for (int i=0;i<n;i++)
    	{
    	   if (s[i]=='R') x++;
    	   if (s[i]=='L') x--;
    	   if (s[i]=='U') y++;
    	   if (s[i]=='D') y--;
    	   if (check(x,y)) xx=x,yy=y;
        }
        cout<<xx<<" "<<yy<<endl;
    }
	return 0;
}