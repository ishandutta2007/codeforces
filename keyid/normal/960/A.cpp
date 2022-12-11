#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

bool check()
{
	string s;
	cin >> s;
	int now=0;
	if (s[0]!='a')
		return false;
	while (now<s.size()&&s[now]=='a')
		now++;
	int c1=now;
	if (now>=s.size()||s[now]!='b')
		return false;
	while (now<s.size()&&s[now]=='b')
		now++;
	int c2=now-c1;
	if (now>=s.size()||s[now]!='c')
		return false;
	while (now<s.size()&&s[now]=='c')
		now++;
	if (now!=s.size())
		return false;
	int c3=now-c2-c1;
	return c3==c1||c3==c2;
}

int main()
{
	printf(check()?"YES":"NO");
	return 0;
}