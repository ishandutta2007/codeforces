#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n, k;
ll x;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%lld%s", &n, &k, &x, s + 1), x--;
		vector<int> v;
		int last = 0;
		for(int i = n;i;i--){
			if(s[i] == 'a'){
				if(last){
					for(int j = 1;j <= x % (k * last + 1);j++) v.push_back('b');
					x /= k * last + 1; 
				}
				v.push_back('a');
				last = 0;
				continue;
			}
			last++;
		}
		if(last){
			for(int j = 1;j <= x % (k * last + 1);j++) v.push_back('b');
			x /= k * last + 1; 
		}
		for(int i = (int)v.size() - 1;~i;i--) printf("%c", v[i]);
		puts("");
	}
}