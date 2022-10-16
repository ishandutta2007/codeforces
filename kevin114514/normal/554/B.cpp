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
int n;
bool state[110][110];
inline void sweep(int col)
{
	for(int i=0;i<n;i++)
		state[i][col]^=1;
}
inline int count_clean()
{
	int cnt=0;
	for(int row=0;row<n;row++)
	{
		bool ok=true;
		for(int col=0;col<n;col++)
			ok&=state[row][col];
		cnt+=ok;
	}
	return cnt;
}
inline int enforce_clean(int row)
{
	for(int col=0;col<n;col++)
		if(!state[row][col])
			sweep(col);
	return count_clean();
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<n;j++)
			if(s[j]=='1')
				state[i][j]=true;
			else	state[i][j]=false;
	}
	int ans=0;
	for(int i=0;i<n;i++)
		ans=max(ans,enforce_clean(i));
	cout<<ans<<endl;
	return 0;
}