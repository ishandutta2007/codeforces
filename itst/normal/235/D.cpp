#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return a;
}

const int _ = 3001;
struct Edge{
	int end , upEd;
}Ed[_ << 1];
int head[_] , cntEd , N;

void addEd(int a , int b){
	Ed[++cntEd] = (Edge){b , head[a]};
	head[a] = cntEd;
}

vector < int > cir;
int dep[_] , bel[_] , len[_];
int getcir(int x , int p){
	dep[x] = dep[p] + 1;
	int cur = 0;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p)
			if(dep[Ed[i].end] && dep[Ed[i].end] < dep[x]){
				cir.push_back(x); return Ed[i].end;
			}
			else if(!dep[Ed[i].end]){
				int t = getcir(Ed[i].end , x);
				if(t) cur = t;
			}
	if(cur) cir.push_back(x);
	else dep[x] = 0;
	return cur == x ? 0 : cur;
}

long double ans;
list < int > dfs(int x , int p , int t){
	list < int > child;
	bel[x] = t; dep[x] = dep[p] + 1;
	child.push_back(dep[x]); ++ans;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!dep[Ed[i].end]){
			list < int > tp = dfs(Ed[i].end , x , t);
			for(auto p : tp)
				for(auto q : child)
					ans += 2.0 / (p + q - 2 * dep[x] + 1);
			child.insert(child.end() , tp.begin() , tp.end());
		}
	return child;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		int a = read() + 1 , b = read() + 1;
		addEd(a , b); addEd(b , a);
	}
	getcir(1 , 0); for(auto t : cir) dfs(t , 0 , t);
	for(int i = 0 ; i < cir.size() ; ++i)
		len[cir[i]] = i + 1;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j){
			int p = bel[i] , q = bel[j];
			if(p != q){
				int a = dep[i] + dep[j];
				if(len[p] > len[q]) swap(p , q);
				int b = len[q] - len[p] - 1 , c = cir.size() - 2 - b;
				ans += 1.0 / (a + b + c) + b * 1.0 / (a + b + c) / (a + c) + c * 1.0 / (a + b + c) / (a + b);
			}
		}
	cout << fixed << setprecision(8) << ans;
	return 0;
}