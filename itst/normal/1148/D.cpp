#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
//This code is written by Itst
using namespace std;

int read(){
	int a = 0; bool f = 0;
	char c = getchar();
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

const int _ = 3e5 + 3;
namespace segTree{
	int maxN[_ << 3] , id[_ << 3];

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)

	void up(int x){
		maxN[x] = max(maxN[lch] , maxN[rch]);
		id[x] = maxN[lch] == maxN[x] ? id[lch] : id[rch];
	}
	
	void modify(int x , int l , int r , int tar , int num , int p){
		if(l == r){maxN[x] = num; id[x] = p; return;}
		if(mid >= tar) modify(lch , l , mid , tar , num , p);
		else modify(rch , mid + 1 , r , tar , num , p);
		up(x);
	}

#define PII pair < int , int >
	PII query(int x , int l , int r , int L , int R){
		if(l >= L && r <= R) return PII(maxN[x] , id[x]);
		PII Max = PII(0 , 0);
		if(mid >= L) Max = query(lch , l , mid , L , R);
		if(mid < R) Max = max(Max , query(rch , mid + 1 , r , L , R));
		return Max;
	}
}
using namespace segTree;
struct num{
	int a , b , id;
}now[_];
int pre[_] , cnt[_] , N , all , aid;
bool cmp1(num a , num b){return a.b < b.b;}
bool cmp2(num a , num b){return a.b > b.b;}

signed main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		now[i].a = read(); now[i].b = read(); now[i].id = i;
	}
	sort(now + 1 , now + N + 1 , cmp2);
	for(int i = 1 ; i <= N ; ++i)
		if(now[i].a < now[i].b){
			PII P = query(1 , 1 , 2 * N , now[i].a , 2 * N);
			cnt[i] = P.first + 1;
			pre[now[i].id] = P.second;
			if(all < cnt[i]){all = cnt[i]; aid = now[i].id;}
			modify(1 , 1 , 2 * N , now[i].b , cnt[i] , now[i].id);
		}
	memset(maxN , 0 , sizeof(maxN)); memset(id , 0 , sizeof(id));
	sort(now + 1 , now + N + 1 , cmp1);
	for(int i = 1 ; i <= N ; ++i)
		if(now[i].a > now[i].b){
			PII P = query(1 , 1 , 2 * N , 1 , now[i].a);
			cnt[i] = P.first + 1;
			pre[now[i].id] = P.second;
			if(all < cnt[i]){all = cnt[i]; aid = now[i].id;}
			modify(1 , 1 , 2 * N , now[i].b , cnt[i] , now[i].id);
		}
	cout << all << endl;
	vector < int > ans;
	for(int i = aid ; i ; i = pre[i]){
		ans.push_back(i);
	}
	reverse(ans.begin() , ans.end());
	for(auto t : ans) cout << t << ' ';
	return 0;
}