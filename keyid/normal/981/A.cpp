#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

int main()
{
	string s;
	cin >> s;
	int ans=0;
	for (int i=0;i<s.length();i++)
		for (int j=i;j<s.length();j++)
		{
			bool flag=false;
			for (int k=0;k<=j-i;k++)
				if (s[i+k]!=s[j-k])
				{
					flag=true;
					break;
				}
			if (flag)
				ans=max(ans,j-i+1);
		}
	cout << ans;
	return 0;
}