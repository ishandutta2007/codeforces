#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

ll pw(ll p, ll q){
	ll ret = 1;
	for(; q; q>>=1){
		if (q & 1){
			ret = ret * p % MM;
		}
		p = p * p % MM;
	}
	return ret;
}

char s[MAXN];

int main() {
	scanf("%s", s);
	int l = strlen(s);
	ll ans = 0;
	for(int i = 0; i < l; i++)
		if ((s[i] - '0') % 4 == 0)
			ans++;
	for(int i = 1; i < l; i++){
		if (((s[i-1]-'0') * 10 + s[i] - '0') % 4 == 0)
			ans += i;
	}
	cout<<ans<<endl;
	return 0;
}