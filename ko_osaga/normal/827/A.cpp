#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 2000005;

char ans[MAXN], buf[MAXN];
set<int> s;

int maxlen, n;

int main(){
	scanf("%d",&n);
	for(int i=0; i<=2000000; i++) s.insert(i);
	while(n--){
		scanf("%s", buf);
		int l = strlen(buf), k;
		scanf("%d",&k);
		while(k--){
			int x;
			scanf("%d",&x);
			x--;
			auto it = s.lower_bound(x);
			while(it != s.end()){
				if(*it - x >= l) break;
				ans[*it] = buf[*it - x];
				it = s.erase(it);
			}
			maxlen = max(maxlen, x + l - 1);
		}
	}
	for(int i=0; i<maxlen; i++){
		if(!ans[i]) ans[i] = 'a';
	}
	puts(ans);
}