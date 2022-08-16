#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 5005;
int A[N], B[N], perm[N];

bool cmp(int i, int j){
	return (A[i] < A[j]) || (A[i] == A[j] && B[i] < B[j]);
}

int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++)
		sd(A[i]), sd(B[i]), perm[i] = i;
	sort(perm + 1, perm + n + 1, cmp);
	int t = 0;
	for(int i = 1; i <= n; i++){
		if(B[perm[i]] < t) t = A[perm[i]];
		else t = B[perm[i]];
	}
	printf("%d\n", t);
}