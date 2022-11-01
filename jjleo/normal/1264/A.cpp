#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int t;
int n;
int a[maxn];
vector<int> v;
int sum;

int main(){
	a[0] = -1;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		v.clear(), sum = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] ^ a[i - 1]) v.push_back(1);
			else v[v.size() - 1]++;
			sum++;
			if(sum * 2 > n){
				sum -= v.back();
				v.pop_back();
				break;
			}
		}
		sum -= v[0];
		int tot = 0;
		bool tag = false;
		for(int i = 1;i < v.size();i++){
			tot += v[i];
			if(tot > v[0] && sum - tot > v[0]){
				tag = true;
				printf("%d %d %d\n", v[0], tot, sum - tot);
				break;
			}
		}
		if(!tag) puts("0 0 0");
	} 
}