#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m;
map<pair<int, int>, int> col;
long long cnt, sum;
char s[maxn];
int x, y;

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%s", s);
		if(s[0] == '+'){
			scanf("%d%d%s", &x, &y, s);
			col[{x, y}] = s[0];
			int a = s[0], b = col[{y, x}];
			if(b){
				if(a == b) cnt++;
				sum++;
			}
		}else if(s[0] == '-'){
			scanf("%d%d", &x, &y);
			int a = col[{x, y}], b = col[{y, x}];
			col[{x, y}] = 0;
			if(b){
				if(a == b) cnt--;
				sum--;
			}
		}else{
			scanf("%d", &x);
			puts((x & 1 ? sum : cnt) ? "YES" : "NO");
		}
	}
}