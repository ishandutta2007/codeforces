#include <bits/stdc++.h>
using namespace std;

const int N = 2018;

char s[N], t[N], tmp[N];

int n, ca[30], cb[30];

vector <int> ans;

void doit(int k){
	int m = 0;
	ans.push_back(k);
	for(int i = n; i > n - k; i--) tmp[++m] = s[i];
	for(int i = 1; i <= n - k; i++) tmp[++m] = s[i];
	for(int i = 1; i <= n; i++) s[i] = tmp[i];
}

int main() {
	scanf("%d", &n);
	scanf("%s%s", s + 1, t + 1);
	for(int i = 1; i <= n; i++){
		ca[s[i] - 'a']++;
	}
	for(int i = 1; i <= n; i++){
		cb[t[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++){
		if(ca[i] != cb[i]){
			puts("-1");
			return 0;
		}
	}
	if(n == 1){
		cout << 0;
		return 0;
	}
	int l = n / 2 + 1, r = n / 2;
	int x = 0;
	for(int i = 1; i <= n; i++){
		if(i & 1){
			if(r == n){
				doit(n);
				continue;
			}
			r++;
			int pos = 0;
			for(int j = 1; j <= n; j++){
				if(s[j] == t[r]){
					pos = j;
					break;
				}
			}
			doit(n - pos + 1);
			doit(pos);
			doit(n - pos - x);
			x++;
		}
		else{
			if(l == 1){
				doit(n);
				continue;
			}
			l--;
			int pos = 0;
			for(int j = 1; j <= n; j++){
				if(s[j] == t[l]){
					pos = j;
					break;
				}
			}
			doit(n - pos + 1);
			doit(pos);
			doit(n - pos - x);
			x++;
		}
	}
	bool ok = 1;
	for(int i = 1; i <= n; i++){
		if(s[i] != t[i]) ok = 0;
	}
	if(!ok) doit(n);
	ok = 1;
	for(int i = 1; i <= n; i++){
		if(s[i] != t[i]) ok = 0;
	}
	printf("%d\n", int(ans.size()));
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	return 0;
}