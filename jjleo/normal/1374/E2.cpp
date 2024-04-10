#include <bits/stdc++.h>
#define maxn 2000086

using namespace std;

struct Node{
	int son[2], val, pri, siz;
	int sum;
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

void up(int x){
	t[x].siz = t[ls(x)].siz + t[rs(x)].siz + 1;
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum + t[x].val; 
}

void split(int x, int val, int &a, int &b){//x val a b 
	if(!x){
		a = b = 0;
		return;
	}
	if(t[x].val <= val) a = x, split(rs(x), val, t[x].son[1], b);
	else b = x, split(ls(x), val, a, t[x].son[0]);
	up(x);
} 

void Split(int x, int k, int &a, int &b){//x k a b 
	if(!x){
		a = b = 0;
		return;
	}
	if(t[ls(x)].siz < k) a = x, Split(rs(x), k - t[ls(x)].siz - 1, t[x].son[1], b);// 
	else b = x, Split(ls(x), k, a, t[x].son[0]);
	up(x);
} 

int merge(int x, int y){// 
	if(x == 0 || y == 0) return x + y;
	if(t[x].pri > t[y].pri){
		t[x].son[1] = merge(rs(x), y);
		up(x);
		return x;
	}else{
		t[y].son[0] = merge(x, ls(y));
		up(y);
		return y;
	}
} 

int newnode(int val){
	cnt++;
	t[cnt].val = t[cnt].sum = val;
	t[cnt].pri = rand();
	t[cnt].siz = 1;
	return cnt;
}

int n, m, k;
vector<pair<int, int> > v[3];
int x, a, b, c, d;
int ans = 2e9 + 5, id;

inline void insert(int x){
	//printf("%d---\n", x);
	split(root, x, a, b);
	root = merge(merge(a, newnode(x)), b);
}

inline void erase(int x){
	split(root, x, a, b);
	split(a, x - 1, c, d);
	root = merge(merge(c, merge(ls(d), rs(d))), b);
}
void dfs(int i){
	if(!i) return;
	dfs(ls(i));
	printf("%d ", t[i].val);
	dfs(rs(i));
}

inline int query(int x){
	if(!x) return 0;
	int a, b;
	Split(root, x, a, b);
	int sum = t[a].sum;
	//printf("%d %d %d--\n", x, a, sum);
	root = merge(a, b);
	return sum;
}

priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>> > q;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d", &x, &a, &b);
		if(!a && !b){
			insert(x), q.push({x, i});
			continue;
		}
		if(a && b) v[0].push_back({x, i}), insert(x);
		else if(a) v[1].push_back({x, i});
		else v[2].push_back({x, i});
	}
	if(v[0].size() + v[1].size() < k || v[0].size() + v[2].size() < k) return printf("-1"), 0;
	if(v[0].size() < k && v[0].size() + 2 * (k - v[0].size()) > m) return printf("-1"), 0;
	for(int i = 0;i < 3;i++) sort(v[i].begin(), v[i].end());
	for(int i = 0;i < 3;i++){
		for(int j = 1;j < v[i].size();j++) v[i][j].first += v[i][j - 1].first;
	}
	for(int i = 1;i < 3;i++) for(int j = k;j < v[i].size();j++) insert(v[i][j].first - v[i][j - 1].first);
	
	if(v[1].size() >= k && v[2].size() >= k){
		if(2 * k <= m){
			int sum = v[1][k - 1].first + v[2][k - 1].first + query(m - 2 * k);
			if(sum < ans) ans = sum, id = 0;
		}
	}
	if(v[1].size() >= k) insert(v[1][k - 1].first - (k - 1 ? v[1][k - 2].first : 0));
	if(v[2].size() >= k) insert(v[2][k - 1].first - (k - 1 ? v[2][k - 2].first : 0));
	for(int i = 0;i < k - 1 && i < v[0].size();i++){
		erase(v[0][i].first - (i ? v[0][i - 1].first : 0));
		if(k - 2 - i >= 0 && k - 2 - i < v[1].size() && k - 2 - i < v[2].size()){
			if(i + 1 + 2 * (k - (i + 1)) <= m){
				int sum = v[0][i].first + v[1][k - 2 - i].first + v[2][k - 2 - i].first + query(m - (i + 1 + 2 * (k - (i + 1))));
				if(sum < ans) ans = sum, id = i + 1;
			}
		}
		if(k - 2 - i >= 0 && k - 2 - i < v[1].size()) insert(v[1][k - 2 - i].first - (k - 2 - i ? v[1][k - 3 - i].first : 0));
		if(k - 2 - i >= 0 && k - 2 - i < v[2].size()) insert(v[2][k - 2 - i].first - (k - 2 - i ? v[2][k - 3 - i].first : 0));
	}
	if(v[0].size() >= k){
		erase(v[0][k - 1].first - (k - 1 ? v[0][k - 2].first : 0));
		//insert(v[1][0].first);
		//insert(v[2][0].first);
		int sum = v[0][k - 1].first + query(m - k);
		if(sum < ans) ans = sum, id = k;
	}
	//if(ans > 2e9) return printf("-1"), 0;
	printf("%d\n", ans);
	for(int i = 0;i < id;i++) printf("%d ", v[0][i].second);
	for(int i = 1;i <= k - id;i++) printf("%d %d ", v[1][i - 1].second, v[2][i - 1].second);
	for(int i = id;i < v[0].size();i++) q.push({v[0][i].first - (i ? v[0][i - 1].first : 0), v[0][i].second});
	for(int i = k - id;i < v[1].size();i++) q.push({v[1][i].first - (i ? v[1][i - 1].first : 0), v[1][i].second});
	for(int i = k - id;i < v[2].size();i++) q.push({v[2][i].first - (i ? v[2][i - 1].first : 0), v[2][i].second});
	for(int i = m - id - (k - id) * 2;i;i--){
		printf("%d ", q.top().second), q.pop();
	}
}