#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))

const int ITER = 30;
int n;
set<int> odd, even;

int get(int x, int y){
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int t;
	scanf("%d", &t);
	return t; 
}

const int N = 1000;
int suff[N];

int go(int l, int t){
	int enter_t = t;
	odd.clear();	
	int now_t = t;
	for(int i = 1; i <= ITER; i++){
		now_t = get(l, n);
		if(i & 1){
			odd.insert(now_t - enter_t);
		}
	}
	auto it = odd.begin();
	if(*it ==  n - 2 * t && odd.size() == 2) it++;
	int L = n - l + 1;
	suff[l] = (L - *it) / 2;
	return now_t;
}
int ans[N];
int main(){
	int t;
	sd(n); sd(t);
	for(int i = 1; i <= n; i++){
		t = go(i, t);
	}
	printf("! ");
	for(int i = 1; i <= n; i++) printf("%d", suff[i] - suff[i + 1]);
}