#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;

int n, a[MAXN];
lint w;

int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%lld",&w);
		for(int i=1; i<=n; i++) scanf("%d",&a[i]);
		auto func = [&](){
			vector<int> v;
			lint sum = 0;
			for(int i=1; i<=n; i++){
				if(a[i] > w) continue;
				if(a[i] >= (w+1)/2){
					printf("1\n%d\n", i);
					return;
				}
				else{
					v.push_back(i);
					sum += a[i];
				}
			}
			if(sum < (w+1)/2){
				puts("-1");
				return;
			}
			while(sum > w){
				sum -= a[v.back()];
				v.pop_back();
			}
			printf("%d\n", sz(v));
			for(auto &i : v) printf("%d ", i);
			puts("");
		};
		func();
	}
}