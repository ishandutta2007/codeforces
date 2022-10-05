#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18;

int n, x, c[N];
vector<int> v;

int main(){
	scanf("%d%d", &n, &x);
	for(int i = 0; i < (1<<n); i++){
		if(!c[i]){
			c[i] = c[i^x] = 1;
			if(i) v.push_back(i);
		}
	}
	printf("%d\n", v.size());
	for(int i = 0, j = 0; i < v.size(); i++){
		printf("%d ", j ^ v[i]);
		j = v[i];
	}
	puts("");
}