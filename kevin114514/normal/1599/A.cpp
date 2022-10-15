#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
//#define ll long long
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
int w[200200];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>w[i];
	sort(w,w+n);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<n-1;i++)
		cnt+=(s[i]!=s[i+1]);
	int pos=n-cnt-1;
	int l=pos,r=pos;
	bool ll=(s[0]=='R'),rr=(s[0]=='R');
	cout<<w[pos]<<" "<<(ll?"R":"L")<<endl;
	for(int i=0;i<n-1;i++)
		if(s[i]==s[i+1])
		{
			l--;
			ll^=1;
			cout<<w[l]<<" "<<(ll?"R":"L")<<endl;
		}
		else
		{
			r++;
			rr^=1;
			cout<<w[r]<<" "<<(rr?"R":"L")<<endl;
		}
	return 0;
}