#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

bool check(char c)
{
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int main()
{
	char s[55];
	scanf("%s",s);
	int l=strlen(s),cnt=0;
	for (int i=0;i<l;i++)
		if (isdigit(s[i]))
		{
			if (s[i]-'0'&1)
				cnt++;
		}
		else if (check(s[i]))
			cnt++;
	printf("%d",cnt);
	return 0;
}