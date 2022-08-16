#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 1e6 + 10;
int bit[N], A[N];
inline void update(int i, int v){
	i++;
	for(; i < N; i += (i & (-i))) bit[i] += v;
}

inline int get(int i){
	i++;
	int ret = 0;
	for(; i; i -= (i & (-i))) ret += bit[i];
	return ret;
}

inline int get(int i, int j){
	return get(j) - get(i - 1);
}

int curr = 0, lft = 1, rgt = 0, len = 0;

int leftfold(int p){
	for(int i = 0; i < p; i++){
		A[curr + p + p - 1 - i] += A[curr + i];
		update(curr + p + p - 1 - i, A[curr + i]);
	}
	curr += p;
	len -= p;
}

int rightfold(int p){
	// fold last p
	for(int i = 0; i < p; i++){
		A[curr + len - p - i - 1] += A[curr + len - p + i];
		update(curr + len - p - i - 1, A[curr + len - p + i]);
	}
	len -= p;
}

void update(int p){
	if(lft){
		if(2 * p <= len){
			leftfold(p);
		}
		else{
			rightfold(len - p);
			lft = 0;
			rgt = 1;
		}
	}
	else{
		if(2 * p <= len){
			rightfold(p);
		}
		else{
			lft = 1;
			rgt = 0;
			leftfold(len - p);
		}
	}
}


int getwidth(int l, int r){
	int L = curr + l, R = curr + r;
	if(rgt){
		L = curr + len - 1- r;
		R = curr + len - 1- l;
	}

	return get(L, R);
}

int main(){
	int n, q, l, r, p, type;
	sd(n); sd(q);
	len = n;
	for(int i = 0; i < n; i++){
		A[i] = 1;
		update(i, 1);
	}
	while(q--){
		sd(type);
		if(type == 1){
			sd(p);
			update(p);
			/*if(lft){for(int i = curr; A[i]; i++) cerr << A[i] << " "; cerr << endl;}
			if(rgt){for(int i = curr + len - 1; i >= curr; i--) cerr << A[i] << " "; cerr << endl;}*/
			continue;
		}
		sd(l); sd(r);
		printf("%d\n", getwidth(l, r - 1));
	}
}