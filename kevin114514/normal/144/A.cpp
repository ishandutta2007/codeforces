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
int a[110];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int mn=0,mx=0;
	for(int i=0;i<n;i++)
		if(a[i]==*min_element(a,a+n))
			mn=i;
	for(int i=0;i<n;i++)
		if(a[i]==*max_element(a,a+n))
		{
			mx=i;
			break;
		}
	cout<<mx+n-mn-1-(mx>mn)<<endl;
	return 0;
}