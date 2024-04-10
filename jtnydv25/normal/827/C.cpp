#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 10;
int tree[4][10][10][3 * N + 10];
char str[N];
inline int get(char c){
	if(c == 'A')
		return 0;
	if(c == 'G')
		return 1;
	if(c == 'T')
		return 2;
	return 3;
}
void make(int s, int e, int ind){
	if(s == e){
		for(int i = 0; i < 10; i++)
			tree [get(str[s])] [i] [s % (i + 1)] [ind]++;
		return;
	}

	int mid = (s + e) >> 1;
	make(s, mid, ind << 1);
	make(mid + 1, e, 2 * ind + 1);

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 10; j++)
			for(int k = 0; k < j + 1; k++){
				tree[i][j][k][ind] = tree[i][j][k][ind << 1] + tree[i][j][k][ind << 1 | 1];
			}
}

void update(int s, int e, int ind, int i, int nw){
	if(i > e || i < s) return;
	if(i >= s && i <= e){
		int curr = get(str[i]);
		for(int j = 0; j < 10; j++){
			tree[nw][j][i % (j + 1)][ind]++;
			tree[curr][j][i % (j + 1)][ind]--;
		}
		if(s == e)
			return;
	}

	int mid = (s + e) >> 1;
	update(s, mid, 2 * ind, i, nw);
	update(mid + 1, e, 2 * ind + 1, i, nw);
}

char x[10];
int get(int s, int e, int ind, int l, int r, int k){
	if(s > r || l > e) return 0;
	if(s >= l && e <= r){
		int ret = 0;
		for(int i = 0; i < k; i++){
			ret += tree[get(x[i])][k - 1][(i + l) % k][ind];
		}

		return ret;
	}
	int mid = (s + e) >> 1;
	return get(s, mid, 2 * ind, l, r, k) + get(mid + 1, e, 2 * ind + 1, l, r, k);
}

int n;

void make(){
	make(1, n, 1);
}

void update(int i, char c){
	update(1, n, 1, i, get(c));
	str[i] = c;
}

int main(){
	scanf("%s", str + 1);
	n = strlen(str + 1);
	make();


	int q;
	scanf("%d", &q);
	while(q--){
		int type;
		scanf("%d", &type);
		if(type == 1){
			int i; char c;
			scanf("%d %c", &i, &c);
			update(i, c);
			continue;
		}
		int l, r;
		scanf("%d %d %s", &l, &r, x);
		printf("%d\n", get(1, n, 1, l, r, strlen(x)));
	}
}