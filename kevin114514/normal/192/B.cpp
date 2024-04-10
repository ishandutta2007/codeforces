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
int x[1010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	int ans=1e7;
	for(int i=0;i<=n;i++)
		ans=min(ans,max(x[i],x[i+1]));
	cout<<ans<<endl;
	return 0;
}