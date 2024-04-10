#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
#define INF 9999999999
#define LINF 9999999999999999
#define SINF "%"
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define sint short int
#define usint unsigned sint
#define xsize(a) sizeof(a)/1024/1024
#define fr(aaaaa,bbbbb) for(aaaaa = 1;aaaaa <= bbbbb;aaaaa++)
#define frr(aaaaa,bbbbb,ccccc) for(aaaaa = ccccc;aaaaa <= bbbbb;aaaaa++)
using namespace std;

#define MAXN 100010

int where[MAXN];
//where[i]=x	:	idi(data[x]) where[i] =data[x].id

class V{
public:
	int id; //1~n
	int chudu_;
};
V makev(int a,int b){
	V v1;
	v1.id = a;
	v1.chudu_ = b;
	return v1;
}
bool operator <(V v1,V v2){
	if(v1.chudu_ != v2.chudu_) return v1.chudu_ < v2.chudu_;
	else return v1.id > v2.id;
}
#define lson (pos << 1)
#define rson (pos << 1 | 1)
class Heap{
public:
	V data[4*MAXN];
	int ge;
	void init(){
		ge = 0;
		msn(data,-1);
	}
	void pushup(int pos){
		while(pos > 1){
			if(data[pos] < data[pos >> 1]){
				swap(data[pos],data[pos >> 1]);
				swap(where[data[pos].id],where[data[pos >> 1].id]);
				pos = pos >> 1;
			}else{
				return;
			}
		}
	}
	V getmin(){
		pushup(2);
		return data[1];
	}
	void pushdown(int pos){
		//if(ge <= 1) return;
		while(data[pos].id != -1){
			if(rson <= ge){
				if(data[rson] < data[lson] && data[rson] < data[pos]){
					swap(data[pos],data[rson]);
					swap(where[data[pos].id],where[data[rson].id]);
					pos = rson;
				}else if(data[lson] < data[rson] && data[lson] < data[pos]){
					swap(data[pos],data[lson]);
					swap(where[data[pos].id],where[data[lson].id]);
					pos = lson;
				}else
					return;
			}else
				return;
		}
	}
	void delmin(){
		if(ge == 0) return;
		data[1] = data[ge];
		where[data[1].id] = 1;
		ge--;
		pushdown(1);
	}
	void push(V x){
		ge++;
		data[ge] = x;
		where[x.id] = ge;
		pushup(ge);
	}
	V get(int pos){
		return data[pos];
	}
	void change(int pos,V x){
		data[pos] = x;
		where[x.id] = pos;
		if(data[pos] < data[pos >> 1]) pushup(pos);
		else pushdown(pos);
	}
};
Heap heap;

int n,m;

vector<int> e[MAXN];
bool vis[MAXN];

int chudu_pre[MAXN];

void ok(int pos){
	for(uint i = 0;i < e[pos].size();i++){
		if(!vis[e[pos][i]]){
			V newv;
			newv.id = e[pos][i];
			newv.chudu_ = heap.data[where[e[pos][i]]].chudu_ - 1;
			heap.change(where[e[pos][i]],newv);
		}
	}
}
int label[MAXN];

int main(){
	ms(chudu_pre); ms(vis);
	//freopen("1.txt","r",stdin);
	
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int a,b;
		cin >> a >> b;
		e[b].pb(a);
		chudu_pre[a]++;
	}
	
	for(int i = 1;i <= n;i++)
		heap.push(makev(i,chudu_pre[i]));
	
	for(int nowlabel = n;nowlabel >= 1;nowlabel--){
		V now;
		now = heap.getmin();
		heap.delmin();
		label[now.id] = nowlabel;
		ok(now.id);
		vis[now.id] = 1;
	}
	
	for(int i = 1;i <= n;i++)
		cout << label[i] << " ";
	cout << endl;
	
	return 0;
}