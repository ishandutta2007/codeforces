#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int M = 30;
const int MAXN = 2 * N * M;
int lft[MAXN], rgt[MAXN], val[MAXN], root = 1, cnt = 1;
void insert(int v){
	int rt = root;
	for(int i = M - 1; i >= 0; i--){
		val[rt]++;
		if(!(v >> i & 1)){
			if(!lft[rt]) lft[rt] = ++cnt;
			rt = lft[rt];
		} else{
			if(!rgt[rt]) rgt[rt] = ++cnt;
			rt = rgt[rt];
		}
	}
	val[rt]++;
}

int getMin(int v){
	int rt =root;
	int ans = 0;
	for(int i = M - 1; i >= 0; i--){
		val[rt]--;
		if(!(v >> i & 1)){
			// go left if possible
			if(val[lft[rt]]) rt = lft[rt];
			else{
				ans += (1 << i);
				rt = rgt[rt];
			}
		} else{
			if(val[rgt[rt]]) rt = rgt[rt];
			else{
				rt = lft[rt];
				ans += (1 << i);
			}
		}
	}
	val[rt]--;
	return ans;
}
int A[N], P[N];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", A + i);
	for(int i = 1; i <= n; i++) scanf("%d", P + i), insert(P[i]);
	for(int i = 1; i <= n; i++) printf("%d ", getMin(A[i]));
}