#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
const ll INF = (1LL) << 60;

char s[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		int x = 0, y = 0;
		for(int j = i; j < n; j++){
			if (s[j] == 'U')
				x++;
			if (s[j] == 'D')
				x--;
			if (s[j] == 'R')
				y++;
			if (s[j] == 'L')
				y--;
			if (x == 0 && y == 0)
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}