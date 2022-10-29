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

char s[MAXN], t[MAXN];

int main() {
	int n, k;
	cin>>n>>k;
	scanf("%s", s);
	int l = strlen(s);
	for(int i = 0; i < l; i++){
		if ('z' - s[i] > s[i] - 'a'){
			if ('z' - s[i] <= k){
				t[i] = 'z';
				k -= 'z' - s[i];
			}
			else{
				t[i] = s[i] + k;
				k = 0;
			}
		}
		else{
			if (s[i] - 'a'<= k){
				t[i] = 'a';
				k -= s[i] - 'a';
			}
			else{
				t[i] = s[i] - k;
				k = 0;
			}
		}
	}
	t[l] = 0;
	if (k > 0)
		puts("-1");
	else
		printf("%s\n", t);
	return 0;
}