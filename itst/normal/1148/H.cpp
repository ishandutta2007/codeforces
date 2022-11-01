#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int N;

#define ll long long
#define mid ((l + r) >> 1)
const int _ = 2e5 + 7;
namespace segt1{
	const int __ = 1e7 + 7;
	int ch[__][2] , mrk[__] , lft[__] , val[__][2] , bin[__] , bint , cnt; ll sum[__];
	int alc(int x){
		int t; if(!bint) t = ++cnt; else t = bin[bint--];
		val[t][0] = val[x][0]; val[t][1] = val[x][1]; ch[t][0] = ch[x][0]; ch[t][1] = ch[x][1];
		mrk[t] = mrk[x]; sum[t] = sum[x]; lft[t] = lft[x]; return t;
	}
	void mark(int &x , int l , int r , int v){x = alc(x); mrk[x] = v; sum[x] = v * (r - l + 1ll); lft[x] = l; val[x][0] = val[x][1] = v;}
	void dw(int &x , int l , int r){if(mrk[x]){mark(ch[x][0] , l , mid , mrk[x]); mark(ch[x][1] , mid + 1 , r , mrk[x]); mrk[x] = 0;}}
	void mdf(int &x , int l , int r , int L , int v){
		if(r < L || val[x][0] >= v) return;
		if(l >= L && val[x][1] <= v) return mark(x , l , r , v);
		x = alc(x); dw(x , l , r); mdf(ch[x][0] , l , mid , L , v); mdf(ch[x][1] , mid + 1 , r , L , v);
		sum[x] = sum[ch[x][0]] + sum[ch[x][1]]; lft[x] = lft[ch[x][0] ? ch[x][0] : ch[x][1]];
		val[x][0] = val[ch[x][0]][0]; val[x][1] = val[ch[x][1]][1];
	}
	ll qry(int x , int l , int r , int L , int &R){
		if(!x) return 0;
		if(l >= L && r <= R){R = lft[x] - 1; return sum[x];}
		if(mrk[x]){ll sum = mrk[x] * (min(R , r) - max(L , l) + 1ll); R = l - 1; return sum;}
		ll sum = 0; if(mid < R) sum = qry(ch[x][1] , mid + 1 , r , L , R);
		if(mid >= L) sum += qry(ch[x][0] , l , mid , L , R);
		return sum;
	}
	int stk[__] , top;
	void erase(int x){
		if(!sum[x]) return;
		stk[top = 1] = x;
		while(top){
			int t = stk[top--]; bin[++bint] = t;
			if(ch[t][0] && sum[ch[t][0]]) stk[++top] = ch[t][0];
			if(ch[t][1] && sum[ch[t][1]]) stk[++top] = ch[t][1];
			sum[t] = ch[t][0] = ch[t][1] = 0;
		}
	}
}

int NUM = 0;
struct opr{int x , y , v; friend bool operator <(opr p , opr q){return p.x < q.x;}}; vector < opr > tmp;
struct data{
	int len; vector < opr > mdf; vector < int > rt; bool built; data(){len = built = 0;}
	void merge(data &q){
		for(auto t : rt) segt1::erase(t);
		for(auto t : q.rt) segt1::erase(t);
		tmp.clear(); std::merge(mdf.begin() , mdf.end() , q.mdf.begin() , q.mdf.end() , back_inserter(tmp));
		rt.clear(); mdf = tmp; len = mdf.size(); built = 0;
	}
	void build(){
		if(!built){
			for(auto p : mdf){rt.push_back(rt.empty() ? 0 : rt.back()); segt1::mdf(rt.back() , 0 , N , p.y , p.v); ++NUM;}
			built = 1;
		}
	}
	ll qry(int v , int l , int &r){
		build();
		int t = upper_bound(mdf.begin() , mdf.end() , (opr){v}) - mdf.begin();
		return t ? segt1::qry(rt[t - 1] , 0 , N , l , r) : 0;
	}
}; vector < data > op; int pre[_];

namespace segt2{
	const int __ = 4e6 + 7; int mn[__] , ch[__][2] , cnt;
	int alc(int x){int t = ++cnt; mn[t] = mn[x]; ch[t][0] = ch[x][0]; ch[t][1] = ch[x][1]; return t;}
	void mdf(int &x , int l , int r , int t , int v){
		x = alc(x); if(l == r){mn[x] = v; return;}
		mid >= t ? mdf(ch[x][0] , l , mid , t , v) : mdf(ch[x][1] , mid + 1 , r , t , v);
		mn[x] = min(mn[ch[x][0]] , mn[ch[x][1]]);
	}
	int qry(int x , int l , int r , int R){
		if(r <= R) return mn[x];
		int mn = qry(ch[x][0] , l , mid , R); if(mid < R) mn = min(mn , qry(ch[x][1] , mid + 1 , r , R));
		return mn;
	}
}int rt[_];

ll qry(int l , int r , int k){
	if(!~k) return (r - l + 1ll) * (r - l + 2) / 2;
	int t = r; r = segt2::qry(rt[r] , 0 , N , k); if(r < l) return 0;
	ll sum = (r - l + 1ll) * (t + 1);
	for(auto t = op.rbegin() ; r >= l && t != op.rend() ; ++t) sum -= t->qry(k , l , r);
	return sum;
}

int main(){
	N = read(); ll lastans = 0;
	for(int i = 1 , A , l , r , k ; i <= N ; ++i){
		A = (read() + lastans) % (N + 1);
		l = (read() + lastans) % i + 1; r = (read() + lastans) % i + 1; if(l > r) swap(l , r);
		k = (read() + lastans) % (N + 1);
		segt2::mdf(rt[i] = rt[i - 1] , 0 , N , A , i); data t1; t1.len = 1;
		t1.mdf.push_back((opr){A , pre[A] + 1 , i}); pre[A] = i;
		while(op.size() && op.back().len == t1.len){t1.merge(op.back()); op.pop_back();}
		op.push_back(t1); printf("%lld\n" , lastans = qry(l , r , k - 1) - qry(l , r , k));
	}
	return 0;
}