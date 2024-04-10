#include <bits/stdc++.h>
#define maxn 100086
 
using namespace std; 
 
struct Node{
	int son[2], val, pri, siz;
	bool rev, inv;
}t[maxn];
int cnt;
int root;
 
inline int rand()
{
    static int seed=12345;
    return seed=(int)seed*482711LL%2147483647;
}
 
#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])
 
void update(int x){
	t[x].siz = t[ls(x)].siz + t[rs(x)].siz + 1;
}
 
inline void reverse(int x){
	t[x].rev ^= 1;
	swap(ls(x), rs(x));
}
 
inline void inverse(int x){
	t[x].val ^= 1;
	t[x].inv ^= 1;
}
 
void down(int x){
	if(t[x].rev){
		t[x].rev = false;
		if(ls(x)) reverse(ls(x));
		if(rs(x)) reverse(rs(x));
	} 
	if(t[x].inv){
		t[x].inv = false;
		if(ls(x)) inverse(ls(x));
		if(rs(x)) inverse(rs(x));
	}
} 
 
int newnode(int val){
	cnt++;
	t[cnt].val = val;
	t[cnt].pri = rand();
	t[cnt].siz = 1;
	t[cnt].inv = t[cnt].rev = 0;
	ls(cnt) = rs(cnt) = 0;
	return cnt;
}
 
void split(int x, int k, int &a, int &b){//x??? k????????????? a b?????????? 
	if(!x){
		a = b = 0;
		return;
	}
	down(x);
	if(t[ls(x)].siz < k) a = x, split(rs(x), k - t[ls(x)].siz - 1, t[x].son[1], b);//????????????? 
	else b = x, split(ls(x), k, a, t[x].son[0]);
	update(x);
} 
 
int merge(int x, int y){//???????? 
	if(x == 0 || y == 0) return x + y;
	if(t[x].pri > t[y].pri){
		down(x);
		t[x].son[1] = merge(rs(x), y);
		update(x);
		return x;
	}else{
		down(y);
		t[y].son[0] = merge(x, ls(y));
		update(y);
		return y;
	}
} 
 
int T;
int n;
char a[maxn], b[maxn];
vector<int> v;
 
int x, y, z, l, c, d;
 
void dfs(int i){
	if(!i) return;
	down(i);
	dfs(ls(i));
	printf("%d ", t[i].val);
	dfs(rs(i));
}
 
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%s%s", &n, a + 1, b + 1);
		cnt = 0;
		root = 0;
		for(int i = 1;i <= n;i++){
			root = merge(root, newnode(a[i] - '0'));
		}
		v.clear();
		for(int i = n;i;i--){
			split(root, i - 1, x, y);
			split(y, 1, z, l);
			int val = t[z].val;
			if(val == b[i] - '0'){
				root = merge(x, merge(z, l));
				continue;
			}
			if(i == 1){
				v.push_back(1);
				break;
			}
			split(x, 1, c, d);
			int val2 = t[c].val;
			//printf("%d %d--\n", i, val2);
			if(val2 == b[i] - '0') t[c].val ^= 1, v.push_back(1);
			root = merge(merge(c, d), merge(z, l));
			split(root, i, x, y);
			reverse(x), inverse(x);
			root = merge(x, y);
			v.push_back(i);
		}
		printf("%d", v.size());
		for(int i = 0;i < v.size();i++) printf(" %d", v[i]);
		puts("");
		//dfs(root);
		//puts("---");
	}
}