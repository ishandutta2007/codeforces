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
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	set<int> s;
	for(int i=a;i<=e;i+=a)
		s.insert(i);
	a=b;
	for(int i=a;i<=e;i+=a)
		s.insert(i);
	a=c;
	for(int i=a;i<=e;i+=a)
		s.insert(i);
	a=d;
	for(int i=a;i<=e;i+=a)
		s.insert(i);
	cout<<sz(s)<<endl;
	return 0;
}