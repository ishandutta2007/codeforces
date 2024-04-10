#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

#define int long long
int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

int N , lsh[200003];
#define PII pair < int , int >
vector < PII > pos;

namespace segTree{
	int sum[800003];

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)

	void insert(int x , int l , int r , int tar){
		if(l == r){sum[x] |= 1; return;}
		if(mid >= tar) insert(lch , l , mid , tar);
		else insert(rch , mid + 1 , r , tar);
		sum[x] = sum[lch] + sum[rch];
	}

	int qry(int x , int l , int r , int L , int R){
		if(L > R) return 0;
		if(l >= L && r <= R) return sum[x];
		int all = 0;
		if(mid >= L) all = qry(lch , l , mid , L , R);
		if(mid < R) all += qry(rch , mid + 1 , r , L , R);
		return all;
	}
}

int ch2(int x){return x * (x + 1) / 2;}

signed main(){
#ifndef ONLINE_JUDGE
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		int x = read() , y = read(); lsh[i] = x;
		pos.push_back(PII(x , y));
	}
	sort(lsh + 1 , lsh + N + 1); int cntlsh = unique(lsh + 1 , lsh + N + 1) - lsh - 1;
	sort(pos.begin() , pos.end() , [&](PII x , PII y){return x.second > y.second;});
	int p = 0 , sum = 0;
	while(p < pos.size()){
		int np = p; set < int > newnd;
		while(np < pos.size() && pos[np].second == pos[p].second){
			int t = lower_bound(lsh + 1 , lsh + cntlsh + 1 , pos[np].first) - lsh;
			newnd.insert(t); segTree::insert(1 , 1 , cntlsh , t);
			++np;
		}
		newnd.insert(0); newnd.insert(cntlsh + 1);
		sum += ch2(segTree::sum[1]);
		for(auto t = ++newnd.begin() ; t != newnd.end() ; ++t){
			auto t1 = t; --t1;
			sum -= ch2(segTree::qry(1 , 1 , cntlsh , *t1 + 1 , *t - 1));
		}
		p = np;
	}
	cout << sum;
	return 0;
}