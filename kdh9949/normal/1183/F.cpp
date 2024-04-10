#include <bits/stdc++.h>
using namespace std;

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		int n;
		scanf("%d", &n);
		vector<int> v;
		for(int i = 0, x; i < n; i++){
			scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end(), greater<int>());
		unique(v.begin(), v.end());
		n = v.size();
		if(v.size() == 1){
			printf("%d\n", v[0]);
			continue;
		}
		int a = v[0];
		for(int i = 1; i < n; i++){
			if(v[0] % v[i]){
				a += v[i];
				for(int j = i + 1; j < n; j++){
					if(v[0] % v[j] && v[i] % v[j]){
						a += v[j];
						break;
					}
				}
				break;
			}
		}
		int b = v[1];
		for(int i = 2; i < n; i++){
			if(v[1] % v[i]){
				b += v[i];
				for(int j = i + 1; j < n; j++){
					if(v[1] % v[j] && v[i] % v[j]){
						b += v[j];
						break;
					}
				}
				break;
			}	
		}
		printf("%d\n", max(a, b));
	}
}