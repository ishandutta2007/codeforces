#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = n - k + 1;i <= n;i++) scanf("%d", &s[i]);
		int last;
		if(s[n - k + 1] == 0) last = 0;
		else if(s[n - k + 1] > 0) last = (s[n - k + 1] + n - k) / (n - k + 1);
		else last = -(-s[n - k + 1] / (n - k + 1));
		bool tag = false;
		for(int i = n - k + 2;i <= n;i++){
			if(s[i] - s[i - 1] >= last) last = s[i] - s[i - 1];
			else{
				tag = true;
				break;
			}
		}
		puts(tag ? "No" : "Yes");
	}
}