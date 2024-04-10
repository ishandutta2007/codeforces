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

const int _ = 2e5 + 11;
struct DATA{
	int mn , mx , lftmx , rhtmx , sum , mrk;
	DATA(){mn = 0; lftmx = rhtmx = sum = mrk = 0;}
	friend DATA merge(DATA &p , DATA &q){
		DATA t; t.mx = max(p.mx , q.mx);
		if(p.mn == q.mn){
			t.lftmx = p.lftmx; t.rhtmx = q.rhtmx;
			t.mn = p.mn; t.sum = p.sum + q.sum + max(p.rhtmx , q.lftmx);
		}
		else if(p.mn < q.mn){t.mn = p.mn; t.sum = p.sum; t.lftmx = p.lftmx; t.rhtmx = max(p.rhtmx , q.mx);}
		else{t.mn = q.mn; t.sum = q.sum; t.lftmx = max(p.mx , q.lftmx); t.rhtmx = q.rhtmx;}
		return t;
	}

	void mark(int x){mrk += x; mn += x;}
};
namespace segt{
	DATA now[_ << 3];

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
	
	void down(int x){now[lch].mark(now[x].mrk); now[rch].mark(now[x].mrk); now[x].mrk = 0;}

	void M1(int x , int l , int r , int L , int R , int val){
		if(l >= L && r <= R) return now[x].mark(val);
		down(x); if(mid >= L) M1(lch , l , mid , L , R , val);
		if(mid < R) M1(rch , mid + 1 , r , L , R , val);
		now[x] = merge(now[lch] , now[rch]);
	}

	void M2(int x , int l , int r , int tar , int val){
		if(l == r){now[x].mx = val; return;}
		down(x); mid >= tar ? M2(lch , l , mid , tar , val) : M2(rch , mid + 1 , r , tar , val);
		now[x] = merge(now[lch] , now[rch]);
	}
}
int N , Q , arr[_]; set < int > pos[_];

int main(){
	N = read(); Q = read(); for(int i = 1 ; i <= N ; ++i) pos[arr[i] = read()].insert(i);
	for(int i = 1 ; i <= 200000 ; ++i)
		if(pos[i].size()){
			segt::M2(1 , 1 , 2 * N + 1 , 2 * (*pos[i].begin()) , pos[i].size());
			segt::M1(1 , 1 , 2 * N + 1 , 2 * (*pos[i].begin()) , 2 * (*--pos[i].end()) , 1);
		}
	printf("%d\n" , N - segt::now[1].sum);
	while(Q--){
		int p = read() , x = read() , t = arr[p];

		if(pos[t].size() != 1)
			if(p == *pos[t].begin()){
				segt::M2(1 , 1 , 2 * N + 1 , 2 * p , 0);
				segt::M2(1 , 1 , 2 * N + 1 , 2 * (*++pos[t].begin()) , pos[t].size() - 1);
				segt::M1(1 , 1 , 2 * N + 1 , 2 * p , 2 * (*++pos[t].begin()) - 1 , -1);
			}
			else{
				if(p == *--pos[t].end())
					segt::M1(1 , 1 , 2 * N + 1 , 2 * (*----pos[t].end()) + 1 , 2 * (*--pos[t].end()) , -1);
				segt::M2(1 , 1 , 2 * N + 1 , 2 * (*pos[t].begin()) , pos[t].size() - 1);
			}
		else{
			segt::M2(1 , 1 , 2 * N + 1 , 2 * p , 0);
			segt::M1(1 , 1 , 2 * N + 1 , 2 * p , 2 * p , -1);
		}
		
		pos[t].erase(p); pos[arr[p] = x].insert(p);

		if(pos[x].size() != 1)
			if(p == *pos[x].begin()){
				segt::M2(1 , 1 , 2 * N + 1 , 2 * p , pos[x].size());
				segt::M2(1 , 1 , 2 * N + 1 , 2 * (*++pos[x].begin()) , 0);
				segt::M1(1 , 1 , 2 * N + 1 , 2 * p , 2 * (*++pos[x].begin()) - 1 , 1);
			}
			else{
				if(p == *--pos[x].end())
					segt::M1(1 , 1 , 2 * N + 1 , 2 * (*----pos[x].end()) + 1 , 2 * (*--pos[x].end()) , 1);
				segt::M2(1 , 1 , 2 * N + 1 , 2 * (*pos[x].begin()) , pos[x].size());
			}
		else{
			segt::M2(1 , 1 , 2 * N + 1 , 2 * p , 1);
			segt::M1(1 , 1 , 2 * N + 1 , 2 * p , 2 * p , 1);
		}
		printf("%d\n" , N - segt::now[1].sum);
	}
	return 0;
}