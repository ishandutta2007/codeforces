#include<bits/stdc++.h>
using namespace std;

const int _ = 6e5 + 7;
int N , X , arr[_]; stack < int > stk1 , stk2 , stkt;
struct node{vector < int > ch; int l , r , sz , type;}now[_];

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
int mn[_ << 2] , mx[_ << 2] , mrk[_ << 2];
void up(int x){mn[x] = min(mn[lch] , mn[rch]); mx[x] = mn[x] == mn[rch] ? mx[rch] : mx[lch];}
void mark(int x , int val){mn[x] += val; mrk[x] += val;}
void down(int x){if(mrk[x]){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = 0;}}

void init(int x , int l , int r){mn[x] = 1e9; mx[x] = r; if(l != r){init(lch , l , mid); init(rch , mid + 1 , r);}}

void modify(int x , int l , int r , int L , int R , int val){
	if(l >= L && r <= R) return mark(x , val);
	down(x); if(mid >= L) modify(lch , l , mid , L , R , val);
	if(mid < R) modify(rch , mid + 1 , r , L , R , val);
	up(x);
}

int qry(int x , int l , int r , int L , int R){
	if(l >= L && r <= R) return mn[x] == 0 ? mx[x] : -1;
	down(x); int mx = -1; if(mid >= L) mx = qry(lch , l , mid , L , R);
	if(mid < R) mx = max(mx , qry(rch , mid + 1 , r , L , R));
	return mx;
}

long long calc(int id){
	long long sum = 1; for(auto t : now[id].ch) sum += calc(t);
	if(now[id].type) sum += 1ll * now[id].ch.size() * (now[id].ch.size() - 1) / 2 - 1;
	return sum;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> N; for(int i = 1 , x , y ; i <= N ; ++i){cin >> x >> y; arr[x] = y;}
	stk1.push(0); stk2.push(0); int cnt = 0; init(1 , 1 , N);
	for(int i = 1 ; i <= N ; ++i){
		while(stk1.size() > 1 && arr[stk1.top()] <= arr[i]){
			int p = stk1.top(); stk1.pop(); int q = stk1.top() + 1;
			modify(1 , 1 , N , q , p , -arr[p]);
		}
		while(stk2.size() > 1 && arr[stk2.top()] >= arr[i]){
			int p = stk2.top(); stk2.pop();int q = stk2.top() + 1;
			modify(1 , 1 , N , q , p , arr[p]);
		}
		modify(1 , 1 , N , stk1.top() + 1 , i , arr[i]); modify(1 , 1 , N , stk2.top() + 1 , i , -arr[i]);
		modify(1 , 1 , N , i , i , -1e9 + 1); modify(1 , 1 , N , 1 , i , -1);
		stk1.push(i); stk2.push(i);
		
		++cnt; now[cnt].l = now[cnt].r = arr[i]; now[cnt].sz = 1; now[cnt].type = 3; int cur = cnt;
		
		while(!stkt.empty()){
			int t = stkt.top();
			if(now[t].type == 1 && now[t].r == now[cur].l - 1){
				now[t].r = now[cur].r; now[t].sz += now[cur].sz;
				now[t].ch.push_back(cur); cur = t; stkt.pop();
			}
			else if(now[t].type == 2 && now[t].l == now[cur].r + 1){
				now[t].l = now[cur].l; now[t].sz += now[cur].sz;
				now[t].ch.push_back(cur); cur = t; stkt.pop();
			}
			else if(now[t].r == now[cur].l - 1){
				now[++cnt].ch = {t , cur}; now[cnt].l = now[t].l; now[cnt].r = now[cur].r;
				now[cnt].sz = now[t].sz + now[cur].sz; now[cnt].type = 1; cur = cnt; stkt.pop();
			}
			else if(now[t].l == now[cur].r + 1){
				now[++cnt].ch = {t , cur}; now[cnt].l = now[cur].l; now[cnt].r = now[t].r;
				now[cnt].sz = now[t].sz + now[cur].sz; now[cnt].type = 2; cur = cnt; stkt.pop();
			}
			else{
				int id = qry(1 , 1 , N , 1 , i - now[cur].sz); if(id < 0) break;
				now[++cnt].l = now[cur].l; now[cnt].r = now[cur].r; now[cnt].ch.push_back(cur); now[cnt].sz = now[cur].sz;
				while(now[cnt].sz != i - id + 1){
					int t = stkt.top(); now[cnt].ch.push_back(t);
					now[cnt].l = min(now[cnt].l , now[t].l);
					now[cnt].r = max(now[cnt].r , now[t].r);
					now[cnt].sz += now[t].sz; stkt.pop();
				}
				cur = cnt;
			}
		}
		stkt.push(cur);
	}
	cout << calc(stkt.top()) + N;
	return 0;
}