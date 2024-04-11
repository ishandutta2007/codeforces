#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;

char str[MAXN], buf[MAXN];
bitset<MAXN> occ[26], beg;
int q;

void download(int x){
	occ[str[x] - 'a'].reset(x);
}

void upload(int x){
	occ[str[x] - 'a'].set(x);
}

int main(){
	scanf("%s %d", str, &q);
	for(int i=0; str[i]; i++) upload(i), beg[i] = 1;
	while(q--){
		int t; scanf("%d",&t);
		if(t == 1){
			int x; char c;
			scanf("%d %s ", &x,buf);
			c = *buf; x--;
			download(x);
			str[x] = c;
			upload(x);
		}
		else{
			int l, r;
			scanf("%d %d %s",&l,&r,buf);
			l += strlen(buf) - 1;
			l--; r--;
			if(l > r){
				puts("0");
				continue;
			}
			auto mtch = occ[buf[0] - 'a'];
			for(int i=1; buf[i]; i++){
				mtch = (mtch << 1) & occ[buf[i] - 'a'];
			}
			int sum = (mtch >> l).count() - (mtch >> (r + 1)).count();
			printf("%d\n", sum);
		}
	}
}