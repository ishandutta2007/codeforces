#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
	    if(c == '-')
			f = 1;
        c = getchar();
    }
    while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 1e6 + 7;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int N , K , cnt , cntEd , head[MAXN] , in[MAXN];

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
	++in[a];
} 

int dfs(int x , int p){
	vector < int > v;
	bool f = 0;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			f = 1;
			int t = dfs(Ed[i].end , x);
			if(t >= 0)
				if(++t == K)
					++cnt;
				else
					v.push_back(t);
		}
	if(!f)
		return 0;
	sort(v.begin() , v.end());
	while(v.size() >= 2 && v[v.size() - 1] + v[v.size() - 2] > K){
		++cnt;
		v.erase(--v.end());
	}
	if(v.empty())
		return -1;
	return v[v.size() - 1];
}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
	#endif
	N = read();
	K = read();
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a); 
	}
	for(int i = 1 ; i <= N ; ++i)
		if(in[i] != 1){
			if(dfs(i , 0) > 0)
				++cnt;
			break;
		}
	cout << cnt;
	return 0;
}