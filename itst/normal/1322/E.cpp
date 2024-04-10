#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int _ = 5e5 + 7; int fa[_]; int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
int N , A[_] , B[_] , st[_] , V[_] , ans[_]; set < pair < int , int > > seg; multiset < int > len;

void cover(int l , int r , int val){for(int i = find(r) ; i >= l ; i = find(fa[i] = i - 1)) ans[i] = val;}
void mdf(int x){
	if(V[x]){
		int l = x , r = x;
		if(V[x - 1]){auto p = --seg.upper_bound(make_pair(x , 1e9)); l = p->first; len.erase(len.find(p->second - p->first + 1)); seg.erase(p);}
		if(V[x + 1]){auto p = seg.upper_bound(make_pair(x , 1e9)); r = p->second; len.erase(len.find(p->second - p->first + 1)); seg.erase(p);}
		seg.insert(make_pair(l , r)); len.insert(r - l + 1);
	}else{
		auto p = --seg.upper_bound(make_pair(x , 1e9)); int l = p->first , r = p->second; len.erase(len.find(r - l + 1)); seg.erase(p);
		if(l != x){len.insert(x - l); seg.insert(make_pair(l , x - 1));}
		if(r != x){len.insert(r - x); seg.insert(make_pair(x + 1 , r));}
	}
}

void addseg(pair < int , int > nseg , int val){
	if((nseg.second - nseg.first + 1) & 1)
		if(st[nseg.second]) cover(nseg.first - 1 , nseg.first + (nseg.second - nseg.first) / 2 - 1 , val);
		else cover(nseg.first + (nseg.second - nseg.first) / 2 , nseg.second , val);
	else if(!st[nseg.second]) cover(nseg.first - 1 , nseg.second , val);
}

void modify(int x , int val){
	st[x] = 0; if(x != 1){V[x] ^= 1; mdf(x);} if(x != N){V[x + 1] ^= 1; mdf(x + 1);}
	auto p = seg.lower_bound(make_pair(x + 1 , 0));
	if(p != seg.end()) addseg(*p , val);
	if(p != seg.begin()) addseg(*--p , val);
	for(int t = max(x - 1 , 1) ; t <= x + 1 && t <= N ; ++t)
		if(!st[t] && !V[t] && !V[t + 1]) cover(t , t , val);
}

int main(){
	N = read(); for(int i = 1 ; i <= N ; ++i) B[A[i] = i] = read();
	sort(A + 1 , A + N + 1 , [&](int p , int q){return B[p] < B[q];}); int pos = 1 , mx = 0; len.insert(0);
	for(int i = 1 ; i <= N ; ++i){fa[i] = i; st[i] = 1;}
	while(pos <= N){int p = pos; while(pos <= N && B[A[p]] == B[A[pos]]) modify(A[pos++] , B[A[p]]); mx = max(mx , *--len.end());}
	cout << mx / 2 << '\n'; for(int i = 1 ; i <= N ; ++i) printf("%d " , ans[i]);
	return 0;
}