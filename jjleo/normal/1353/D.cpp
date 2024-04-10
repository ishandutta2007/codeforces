#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
struct Node{
	int l, r;
	
	friend inline bool operator < (Node x, Node y){
		return (x.r - x.l + 1) == (y.r - y.l + 1) ? x.l > y.l : (x.r - x.l + 1) < (y.r - y.l + 1);
	}
};

int t;

priority_queue<Node> q;
int a[maxn];
int cnt;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		q.push((Node){1, n}), cnt = 0;
		while(!q.empty()){
			Node node = q.top();q.pop();
			int mid = node.l + node.r >> 1;
			a[mid] = ++cnt;
			if(node.l <= mid - 1) q.push((Node){node.l, mid - 1});
			if(mid + 1 <= node.r) q.push((Node){mid + 1, node.r});
		}
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts("");
	} 
}