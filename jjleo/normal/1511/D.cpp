#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, k;
vector<int> v;

int main(){
	scanf("%d%d", &n, &k);
	if(k == 1){
		for(int i = 1;i <= n;i++) printf("a");
		return 0;
	}
	v.push_back(0);
	for(int i = 0;i < k && v.size() < n;i++){
		v.push_back(i);
		for(int j = i + 2;j < k;j++) v.push_back(j), v.push_back(i);
		if(i + 1 < k) v.push_back(i + 1);
	}
	for(int i = k - 2;i > 0;i--) v.push_back(i);
	for(int i = 0;i < n;i++) printf("%c", v[i % v.size()] + 'a');
}