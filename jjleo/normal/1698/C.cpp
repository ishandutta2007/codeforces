#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];

void solve(){
	scanf("%d", &n);
	vector<int> v;
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		if(a[i]) v.push_back(a[i]);
	}
	if(v.size() > 5){
		puts("NO");
		return;
	}
	for(int i = 1;i <= n;i++){
		if(v.size() < 10 && a[i] == 0) v.push_back(0);
	}
	for(int i = 0;i < v.size();i++){
		for(int j = 0;j < i;j++){
			for(int k = 0;k < j;k++){
				bool tag = false;
				for(int l = 0;l < v.size();l++) if(1ll * v[i] + v[j] + v[k] == v[l]){
					tag = true;
					break;
				}
				if(!tag){
					puts("NO");
					return;
				}
			}
		}
	}
	puts("YES");
}

int main(){
	scanf("%d", &t);
	while(t--) solve();
}