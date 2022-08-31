#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

int a[100005];
set<int> st;
int main(){
	int n, l, x, y;
	sd(n), sd(l), sd(x), sd(y);
	if(x > y) swap(x, y);
	bool fx = 0, fy = 0;
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		if(st.count(a[i] - x)) fx = 1;
		if(st.count(a[i] - y)) fy = 1;
		st.insert(a[i]);
	}
	if(fx && fy){
		printf("0\n");
		return 0;
	}

	if(x == y){
		printf("%d\n%d", 1, x);
		return 0;
	}

	if(fx && !fy){
		printf("%d\n%d", 1, y);
		return 0;
	}

	if(fy && !fx){
		printf("%d\n%d", 1, x);
		return 0;
	}

	for(int i = 1; i <= n; i++){
		int z = a[i] + y;
		if(z <= l && (st.count(z - x) || st.count(z + x))){
			printf("%d\n%d", 1, z);
			return 0;
		}
		z = a[i] - y;
		if(z >= 0 && (st.count(z - x) || st.count(z + x))){
			printf("%d\n%d", 1, z);
			return 0;
		}
	}
	printf("%d\n%d %d", 2, x, y);
}