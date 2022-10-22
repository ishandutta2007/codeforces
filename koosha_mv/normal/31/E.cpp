/*    |>>>                                                      |>>>
    |                     |>>>          |>>>                  |
    *                     |             |                     *
   / \                    *             *                    / \
  /___\                 _/ \           / \_                 /___\
  [   ]                |/   \_________/   \|                [   ]
  [ I ]                /     \       /     \                [ I ]
  [   ]_ _ _          /       \     /       \          _ _ _[   ]
  [   ] U U |        {#########}   {#########}        | U U [   ]
  [   ]====/          \=======/     \=======/          \====[   ]
  [   ]    |           |   I |_ _ _ _| I   |           |    [   ]
  [___]    |_ _ _ _ _ _|     | U U U |     |_ _ _ _ _ _|    [___]
  \===/  I | U U U U U |     |=======|     | U U U U U | I  \===/
   \=/     |===========| I   | + W + |   I |===========|     \=/
    |  I   |           |     |_______|     |           |   I  |
    |      |           |     |||||||||     |           |      |
    |      |           |   I ||vvvvv|| I   |           |      |
_-_-|______|-----------|_____||     ||_____|-----------|______|-_-_
   /________\         /______||     ||______\         /________\
  |__________|-------|________\_____/________|-------|__________|
*/


#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,m,dp[38][20],tavan[22],mxt[109],x;
string s,kh;
int dfs(int x,int y){
	if(x==0) return 0;
	if(x==y){kh+='H';dfs(x-1,y-1);return 0;}
	if(y==0){kh+='M';dfs(x-1,0);return 0;}
	if((dp[x-1][y-1] + (s[x-1]-'0')*tavan[y])==dp[x][y]){
		kh+='H';
		dfs(x-1,y-1);
		return 0;
	}
	kh+='M';
	dfs(x-1,y);
	return 0;
}
int main(){
	tavan[1]=1;
	f(i,2,19) tavan[i]=tavan[i-1]*10;
	cin>>n>>s;n*=2;
	reverse(s.begin(), s.end());
	f(i,1,n+1){
		f(j,0,min(i,n/2)+1){
			if(i-j<=n/2){
				if(j!=0){
					dp[i][j]=dp[i-1][j-1]+(tavan[j]*(s[i-1]-'0'));
				}
				if(i-j>0){
					dp[i][j]=max(dp[i][j],dp[i-1][j]+(tavan[i-j]*(s[i-1]-'0')));
				}
			}
		}
	}
	dfs(n,n/2);

	cout<<kh;
}