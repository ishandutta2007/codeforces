#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 2e5 + 3;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int sz[MAXN] , head[MAXN];
int N , M , cntEd , cnt;
queue < int > q;
deque < int > notin , notto , tmp;

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif
	N = read();
	M = read();
	for(int i = 1 ; i <= M ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
	for(int i = 1 ; i <= N ; ++i)
		notin.push_back(i);
	while(!notin.empty()){
		int t = notin.front();
		notin.pop_front();
		++cnt;
		q.push(t);
		while(!q.empty()){
			int t = q.front();
			q.pop();
			++sz[cnt];
			notto.clear();
			for(int i = head[t] ; i ; i = Ed[i].upEd)
				notto.push_back(Ed[i].end);
			sort(notto.begin() , notto.end());
			tmp.clear();
			while(!notin.empty())
				if(!notto.empty() && notto.front() == notin.front()){
					tmp.push_back(notto.front());
					notto.pop_front();
					notin.pop_front();
				}
				else
					if(notto.empty() || notin.front() < notto.front()){
						q.push(notin.front());
						notin.pop_front();
					}
					else
						notto.pop_front();
			notin = tmp;
		}
	}
	cout << cnt << '\n';
	sort(sz + 1 , sz + cnt + 1);
	for(int i = 1 ; i <= cnt ; ++i)
		cout << sz[i] << ' ';
	return 0;
}