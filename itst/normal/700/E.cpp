#include<iostream>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
//This code is written by Itst
using namespace std;

const int MAXN = 4e5 + 7;

namespace segtree{
	struct node{
		int l , r , sz;
	}Tree[MAXN << 5];
	int rt[MAXN] , cnt;

#define lch Tree[x].l
#define rch Tree[x].r
#define mid ((l + r) >> 1)
	int insert(int t , int l , int r , int tar){
		int x = ++cnt;
		Tree[x] = Tree[t];
		++Tree[x].sz;
		if(l == r) return x;
		if(mid >= tar) lch = insert(lch , l , mid , tar);
		else rch = insert(rch , mid + 1 , r , tar);
		return x;
	}

	int merge(int p , int q){
		if(!p || !q) return p + q;
		int x = ++cnt;
		Tree[x].sz = Tree[q].sz + Tree[p].sz;
		lch = merge(Tree[p].l , Tree[q].l);
		rch = merge(Tree[p].r , Tree[q].r);
		return x;
	}

	bool query(int x , int l , int r , int L , int R){
		if(!Tree[x].sz) return 0;
		if(l >= L && r <= R) return 1;
		if(mid >= L && query(lch , l , mid , L , R)) return 1;
		return mid < R && query(rch , mid + 1 , r , L , R);
	}
}

using segtree::rt; using segtree::merge; using segtree::query;

namespace SAM{
    int Lst[MAXN] , Sst[MAXN] , fa[MAXN] , trans[MAXN][26] , endpos[MAXN];
    int cnt = 1 , lst = 1 , L;
	char s[MAXN];

    void insert(int len , int x){
        int t = ++cnt , p = lst;
        endpos[t] = Lst[lst = t] = len;
        while(p && !trans[p][x]){
            trans[p][x] = t;
            p = fa[p];
        }
        if(!p){Sst[t] = fa[t] = 1; return;}
        int q = trans[p][x];
        Sst[t] = Lst[p] + 2;
        if(Lst[q] == Lst[p] + 1){fa[t] = q; return;}
        int k = ++cnt;
        memcpy(trans[k] , trans[q] , sizeof(trans[k]));
        Lst[k] = Lst[p] + 1; Sst[k] = Sst[q];
        Sst[q] = Lst[p] + 2;
        fa[k] = fa[q]; fa[q] = fa[t] = k;
        while(trans[p][x] == q){
            trans[p][x] = k;
            p = fa[p];
        }
    }

    void init(){
        scanf("%d %s" , &L , s + 1);
        for(int i = 1 ; i <= L ; ++i)
            insert(i , s[i] - 'a');
    }

	vector < int > ch[MAXN];
	int ans = 0 , top[MAXN] , len[MAXN];
	
	void dfs(int x){
		if(endpos[x]) rt[x] = segtree::insert(rt[x] , 1 , L , endpos[x]);
		for(auto t : ch[x]){
			dfs(t);
			if(!endpos[x]) endpos[x] = endpos[t];
			rt[x] = merge(rt[x] , rt[t]);
		}
	}

	void dp(int x){
		if(fa[x])
			if(fa[x] == 1 || query(rt[top[fa[x]]] , 1 , L , endpos[x] - Lst[x] + Lst[top[fa[x]]] , endpos[x] - 1)){
				len[x] = len[fa[x]] + 1;
				top[x] = x;
				ans = max(ans , len[x]);
			}
			else{
				len[x] = len[fa[x]];
				top[x] = top[fa[x]];
			}
		for(auto t : ch[x]) dp(t);
	}
	
	void work(){
		for(int i = 2 ; i <= cnt ; ++i)
			ch[fa[i]].push_back(i);
		dfs(1);
		dp(1);
		cout << ans;
	}
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in" , "r" , stdin);
    //freopen("out" , "w" , stdout);
    #endif
	SAM::init(); SAM::work();
    return 0;
}