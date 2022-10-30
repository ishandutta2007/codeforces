#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

#define PII pair < int , int >
const int _ = 2e5 + 3; mt19937 Rand(1);
vector < PII > cloth; int buy[_] , N , M;
namespace treap{
	int val[_] , ans[_] , rnd[_] , vmrk[_] , amrk[_] , id[_] , ch[_][2] , cnt , rt , r1 , r2 , r3;

	void mark(int x , int v , int a){val[x] -= v; vmrk[x] += v; ans[x] += a; amrk[x] += a;}
	void down(int x){mark(ch[x][0] , vmrk[x] , amrk[x]); mark(ch[x][1] , vmrk[x] , amrk[x]); vmrk[x] = amrk[x] = 0;}
	
	int merge(int p , int q){
		if(!p || !q) return p | q;
		down(p); down(q);
		if(rnd[p] > rnd[q]){ch[p][1] = merge(ch[p][1] , q); return p;}
		ch[q][0] = merge(p , ch[q][0]); return q;
	}

	void split(int now , int k , int &x , int &y){
		if(!now){x = y = 0; return;}
		down(now);
		if(val[now] <= k){x = now; split(ch[now][1] , k , ch[x][1] , y);}
		else{y = now; split(ch[now][0] , k , x , ch[y][0]);}
	}
	
	int alloc(int p , int q){val[++cnt] = p; id[cnt] = q; rnd[cnt] = Rand(); return cnt;}
	void ins(int t){r1 = r2 = 0; split(rt , val[t] , r1 , r2); rt = merge(r1 , merge(t , r2));}
	void insert(int rt){if(!rt) return; down(rt); insert(ch[rt][0]); insert(ch[rt][1]); ch[rt][0] = ch[rt][1] = 0; ins(rt);}

	void modify(int val){
		r1 = r2 = 0; split(rt , val - 1 , r1 , r2); mark(r2 , val , 1);
		int tmp = r2; r2 = 0; split(tmp , val - 1 , r2 , r3);
		rt = r1; insert(r2); rt = merge(rt , r3);
	}

	void getans(int rt){if(!rt) return; down(rt); buy[id[rt]] = ans[rt]; getans(ch[rt][0]); getans(ch[rt][1]);}
}using namespace treap;

int main(){
	N = read(); for(int i = 1 ; i <= N ; ++i){int p = read() , q = read(); cloth.push_back(PII(p , q));}
	M = read(); for(int i = 1 ; i <= M ; ++i) ins(alloc(read() , i));
	sort(cloth.begin() , cloth.end() , [&](PII A , PII B){return A.second > B.second || A.second == B.second && A.first < B.first;});
	for(auto t : cloth)
		modify(t.first);
	getans(rt);
	for(int i = 1 ; i <= M ; ++i) printf("%d " , buy[i]);
	return 0;
}