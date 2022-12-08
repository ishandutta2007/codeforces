#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[100010];

int main()
{
	cin >> s;
	int l=strlen(s);
	int ans=(l+1)/2-1;
	if(l%2==1){for(int i=1;i<l;i++)if(s[i]=='1'){ans++;break;}
	}
	else ans++;
	cout << ans << endl;
	return 0;
}