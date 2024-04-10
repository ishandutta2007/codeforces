#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iomanip>
#define PII pair < int , int >
#define st first
#define nd second
//This code is written by Itst
using namespace std;

const int MAXN = 5e5 + 7 , MAXL = 1e5 + 7;
char s[MAXL] , S[MAXN];
int M , Q , cnt = 1 , ch[MAXL][26] , dep[MAXL] , ind[MAXL];
vector < int > bel[MAXL];
struct Query{
	int a , b , c , d , ind;
	bool operator <(const Query a)const{return d < a.d;}
};
vector < Query > que;
PII ans[MAXN];

namespace Tree{
	struct node{
		int l , r , maxN , sz , ind;
	}Tree[MAXL * 60];
	int rt[MAXL] , cnt = 1;
	
#define lch (Tree[x].l)
#define rch (Tree[x].r)
#define mid ((l + r) >> 1)
	inline void pushup(int x){
		if(Tree[rch].maxN > Tree[lch].maxN){
			Tree[x].maxN = Tree[rch].maxN;
			Tree[x].ind = Tree[rch].ind;
		}
		else{
			Tree[x].maxN = Tree[lch].maxN;
			Tree[x].ind = Tree[lch].ind;
		}
	}
	
	int insert(int x , int l , int r , int tar){
		if(!x) x = ++cnt;
		++Tree[x].sz;
		if(l == r){
			Tree[x].maxN = Tree[x].sz;
			Tree[x].ind = l;
			return x;
		}
		if(mid >= tar) lch = insert(lch , l , mid , tar);
		else rch = insert(rch , mid + 1 , r , tar);
		pushup(x);
		return x;
	}

	PII query(int x , int l , int r , int L , int R){
		if(l >= L && r <= R)
			return PII(Tree[x].maxN , -Tree[x].ind);
		PII sum(0 , 0);
		if(mid >= L)
			sum = max(sum , query(lch , l , mid , L , R));
		if(mid < R)
			sum = max(sum , query(rch , mid + 1 , r , L , R));
		return sum;
	}

	int merge(int p , int q , int l , int r){
		if(!p || !q) return p + q;
		int t = ++cnt;
		Tree[t].sz = Tree[p].sz + Tree[q].sz;
		if(l == r){
			Tree[t].maxN = Tree[t].sz;
			Tree[t].ind = l;
		}
		else{
			Tree[t].l = merge(Tree[p].l , Tree[q].l , l , mid);
			Tree[t].r = merge(Tree[p].r , Tree[q].r , mid + 1 , r);
			pushup(t);
		}
		return t;
	}
}

namespace SAM{
    int Lst[MAXL] , Sst[MAXL] , fa[MAXL] , trans[MAXL][26];
    int cnt = 1;
	
    int insert(int p , int len , int x){
        int t = ++cnt; Lst[t] = len;
        while(p && !trans[p][x]){
            trans[p][x] = t;
            p = fa[p];
        }
        if(!p){
            Sst[t] = fa[t] = 1;
            return t;
        }
        int q = trans[p][x];
        Sst[t] = Lst[p] + 2;
        if(Lst[q] == Lst[p] + 1){
            fa[t] = q;
            return t;
        }
        int k = ++cnt;
        memcpy(trans[k] , trans[q] , sizeof(trans[k]));
        Lst[k] = Lst[p] + 1; Sst[k] = Sst[q];
        Sst[q] = Lst[p] + 2;
        fa[k] = fa[q]; fa[q] = fa[t] = k;
        while(trans[p][x] == q){
            trans[p][x] = k;
            p = fa[p];
        }
		return t;
    }

	vector < int > ch[MAXL] , bel[MAXL];
	int jump[MAXL][20];
	
	void dfs(int x){
		for(auto &t : bel[x])
			Tree::rt[x] = Tree::insert(Tree::rt[x] , 1 , M , t);
		for(int i = 1 ; i <= 18 ; ++i)
			jump[x][i] = jump[jump[x][i - 1]][i - 1];
		
		for(auto &t : ch[x]){
			jump[t][0] = x;
			dfs(t);
			Tree::rt[x] = Tree::merge(Tree::rt[x] , Tree::rt[t] , 1 , M);
		}
	}
	
	void build(){
		for(int i = 2 ; i <= cnt ; ++i)
			ch[fa[i]].push_back(i);
		dfs(1);
	}

	int calc(int x , int l){
		if(Sst[x] <= l) return x;
		for(int i = 18 ; i >= 0 ; --i)
			if(Sst[jump[x][i]] > l)
				x = jump[x][i];
		return jump[x][0];
	}
}

void insert(int ind){
	scanf("%s" , s + 1);
	int L = strlen(s + 1) , cur = 1;
	for(int i = 1 ; i <= L ; ++i){
		if(!ch[cur][s[i] - 'a'])
			dep[ch[cur][s[i] - 'a'] = ++cnt] = dep[cur] + 1;
		bel[cur = ch[cur][s[i] - 'a']].push_back(ind);
	}
}

void build(){
	queue < int > q;
	q.push(ind[1] = 1);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		SAM::bel[ind[t]] = bel[t];
		for(int i = 0 ; i < 26 ; ++i)
			if(ch[t][i]){
				ind[ch[t][i]] = SAM::insert(ind[t] , dep[ch[t][i]] , i);
				q.push(ch[t][i]);
			}
	}
	SAM::build();
}

int main(){
	scanf("%s %d" , S + 1 , &M);
	for(int i = 1 ; i <= M ; ++i)
		insert(i);
	build();
	scanf("%d" , &Q);
	for(int i = 1 ; i <= Q ; ++i){
		Query now;
		scanf("%d %d %d %d" , &now.a , &now.b , &now.c , &now.d);
		now.ind = i;
		que.push_back(now);
	}
	sort(que.begin() , que.end());
	int bef = 0 , u = 1 , len = 0;
	for(auto &q : que){
		while(bef < q.d){
			++bef;
			while(u != 1 && !SAM::trans[u][S[bef] - 'a'])
				len = SAM::Lst[u = SAM::fa[u]];
			if(SAM::trans[u][S[bef] - 'a']){
				++len;
				u = SAM::trans[u][S[bef] - 'a'];
			}
		}
		if(len >= q.d - q.c + 1){
			int t = SAM::calc(u , q.d - q.c + 1);
			ans[q.ind] = Tree::query(Tree::rt[t] , 1 , M , q.a , q.b);
		}
		if(!ans[q.ind].st)
			ans[q.ind].nd = -q.a;
	}
	for(int i = 1 ; i <= Q ; ++i)
		printf("%d %d\n" , -ans[i].nd , ans[i].st);
	return 0;
}