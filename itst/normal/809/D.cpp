#include<bits/stdc++.h>
#define MAXN 300010
#define inf 0x7fffffff
using namespace std;

struct node{
	int ch[2] , fa , num , add;
}Tree[MAXN];
int cntNode = 2 , N , root = 1;

inline bool son(int dir){
	return Tree[Tree[dir].fa].ch[1] == dir;
}

inline void ZigZag(int dir){
	bool f = son(dir);
	if(Tree[dir].fa == root)
		root = dir;
	Tree[Tree[dir].fa].ch[f] = Tree[dir].ch[f ^ 1];
	Tree[Tree[dir].ch[f ^ 1]].fa = Tree[dir].fa;
	int x = Tree[Tree[dir].fa].fa;
	Tree[x].ch[son(Tree[dir].fa)] = dir;
	Tree[Tree[dir].fa].fa = dir;
	Tree[dir].ch[f ^ 1] = Tree[dir].fa;
	Tree[dir].fa = x;
}

inline void pushdown(int dir){
	if(Tree[dir].add){
		Tree[Tree[dir].ch[0]].add += Tree[dir].add;
		Tree[Tree[dir].ch[1]].add += Tree[dir].add;
		Tree[Tree[dir].ch[0]].num += Tree[dir].add;
		Tree[Tree[dir].ch[1]].num += Tree[dir].add;
		Tree[dir].add = 0;
	}
}

inline void Splay(int dir , int fa){
	pushdown(dir);
	while(Tree[dir].fa != fa)
		if(Tree[Tree[dir].fa].fa == fa)
			ZigZag(dir);
		else{
			if(son(Tree[dir].fa) == son(dir))
				ZigZag(Tree[dir].fa);
			else
				ZigZag(dir);
			ZigZag(dir);
		}
}

void insert(int &now , int num , int fa){
	if(now == 0){
		now = ++cntNode;
		Tree[now].num = num;
		Tree[now].fa = fa;
		Splay(now , 0);
		return;
	}
	pushdown(now);
	insert(Tree[now].ch[Tree[now].num < num] , num , now);
}

void getPre(int now , int num , int minN){
	if(now == 0){
		Splay(minN , 0);
		return;
	}
	pushdown(now);
	if(Tree[now].num == num){
		int t = Tree[now].ch[0];
		while(t){
			pushdown(t);
			if(Tree[t].num != num)
				minN = t;
			t = Tree[t].ch[1];
		}
		Splay(minN , 0);
		return;
	}
	if(Tree[now].num < num)
		getPre(Tree[now].ch[1] , num , Tree[now].num > Tree[minN].num ? now : minN);
	else
		getPre(Tree[now].ch[0] , num , minN);
}

void getNXT(int now , int num , int maxN){
	if(now == 0){
		Splay(maxN , root);
		return;
	}
	pushdown(now);
	if(Tree[now].num == num){
		int t = Tree[now].ch[1];
		while(t){
			pushdown(t);
			maxN = t;
			t = Tree[t].ch[0];
		}
		Splay(maxN , root);
		return;
	}
	if(Tree[now].num < num)
		getNXT(Tree[now].ch[1] , num , maxN);
	else
		getNXT(Tree[now].ch[0] , num , Tree[now].num < Tree[maxN].num ? now : maxN);
}

inline void find(int dir){
	if(Tree[dir].fa)
		find(Tree[dir].fa);
	pushdown(dir);
}

int main(){
	srand((unsigned)time(0));
	int ans = 0;
	scanf("%d" , &N);
	Tree[1].ch[1] = 2;
	Tree[2].num = inf;
	Tree[2].fa = 1;
	for(int i = 1 ; i <= N ; i++){
		int a , b;
		scanf("%d%d" , &a , &b);
		getPre(root , a , 1);
		getNXT(root , b - 1 , 2);
		Tree[Tree[Tree[root].ch[1]].ch[0]].add++;
		Tree[Tree[Tree[root].ch[1]].ch[0]].num++;
		if(Tree[Tree[root].ch[1]].ch[1]){
			ZigZag(Tree[root].ch[1]);
			getNXT(Tree[root].ch[1] , Tree[root].num , 2);
			Tree[Tree[root].ch[1]].ch[0] = Tree[root].ch[0];
			root = Tree[root].ch[1];
			Tree[Tree[root].ch[0]].fa = root;
			Tree[root].fa = 0;
		}
		else
			ans++;
		insert(Tree[root].ch[Tree[root].num < a] , a , root);
		int t = rand() % (i + 2) + 1;
		find(t);
		Splay(t , 0);
	}
	cout << ans;
	return 0;
}