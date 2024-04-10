#include<bits/stdc++.h>
#define P pair < int , int >
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

const int MAXN = 5e5 + 10 , INF = 0x7fffffff;
int num[MAXN << 1] , pre[MAXN] , ST[21][MAXN << 1] , logg2[MAXN << 1] , fir[MAXN] , fa[MAXN << 1];
int N;
deque < int > unused;
bool vis[MAXN];

inline int min(int a , int b){
	return a < b ? a : b;
}

inline int query(int l , int r){
	if(r < l)
		return INF;
	int t = logg2[r - l + 1];
	return min(ST[t][l] , ST[t][r - (1 << t) + 1]);
}

inline int get(){
	if(unused.empty()){
		puts("no");
		exit(0);
	}
	int t = unused.front();
	unused.pop_front();
	return t;
}

void init(){
	N = read();
	logg2[0] = -1;
	for(int i = 1 ; i < N << 1 ; ++i){
		vis[num[i] = read()] = 1;
		if(!fir[num[i]])
			fir[num[i]] = i;
	}
	for(int i = 1 ; i <= N ; ++i)
		if(!vis[i])
			unused.push_back(i);
	if(num[(N << 1) - 1] && num[1] && num[(N << 1) - 1] != num[1]){
		puts("no");
		exit(0);
	}
	if(num[1] != num[(N << 1) - 1])
		num[1] = num[(N << 1) - 1] = num[1] + num[(N << 1) - 1];
	for(int i = 1 ; i < N << 1 ; ++i){
		fa[i] = i;
		logg2[i] = logg2[i >> 1] + 1;
		if(!num[i]){
			ST[0][i] = INF;
			continue;
		}
		if(pre[num[i]] && (pre[num[i]] & 1) != (i & 1)){
			puts("no");
			exit(0);
		}
		ST[0][i] = pre[num[i]] ? pre[num[i]] : i;
		pre[num[i]] = i;
	}
	for(int i = 1 ; 1 << i < N << 1 ; ++i)
		for(int j = 1 ; j + (1 << i) - 1 < N << 1 ; ++j)
			ST[i][j] = min(ST[i - 1][j] , ST[i - 1][j + (1 << (i - 1))]);
	for(int i = 1 ; i < N << 1 ; ++i)
		if(num[i] && query(ST[0][i] + 1 , i - 1) < ST[0][i]){
			puts("no");
			exit(0);
		}
}

int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void solve(int l , int r){
	vector < int > cur;
	for(int i = r ; i >= l ; i = find(i - 1)){
		while(cur.size() >= 2){
			if((num[cur[cur.size() - 2]] == num[i] || (!num[i] || !num[cur[cur.size() - 2]])) && (num[i] || num[cur[cur.size() - 2]]) && num[cur[cur.size() - 1]]){
				if(!num[i] || !num[cur[cur.size() - 2]])
					num[i] = num[cur[cur.size() - 2]] = num[i] + num[cur[cur.size() - 2]];
				cur.pop_back();
				cur.pop_back();
			}
			else
				break;
		}
		cur.push_back(i);
	}
	reverse(cur.begin() , cur.end());
	for(int i = 1 ; i < cur.size() ; ++i)
		if(num[cur[i]] && num[cur[i - 1]]){
			puts("no");
			exit(0);
		}
	deque < int > q;
	for(int i = 1 ; i + 1 < cur.size() ; ++i)
		q.push_back(cur[i]);
	if(!num[cur[0]])
		if(num[(N << 1) - 1])
			num[1] = num[(N << 1) - 1];
		else
			num[1] = num[(N << 1) - 1] = get();
	int rt = num[cur[0]];
	while(!q.empty()){
		int p = q.front() , r = q.back();
		if(q.size() == 1){
			if(!num[p])
				num[p] = get();
			q.pop_front();
		}
		else{
			if(!num[p] && !num[r]){
				num[p] = num[r] = get();
				rt = num[p];
				q.pop_front();
				q.pop_back();
			}
			else
				if(!num[p] || !num[r]){
					num[p] = num[r] = num[p] + num[r];
					rt = num[p];
					q.pop_front();
					q.pop_back();
				}
				else{
					num[q[q.size() - 2]] = rt;
					q.pop_back();
					q.pop_back();
				}
		}
	}
	fa[find(r)] = l;
}

void work(){
	for(int i = 1 ; i < N << 1 ; ++i)
		if(num[i] && ST[0][i] != i)
			solve(find(ST[0][i]) , i);
	if(!num[1])
		solve(1 , (N << 1) - 1);
	if(num[1] != num[(N << 1) - 1]){
		puts("NO");
		exit(0);
	}
}

int main(){
	init();
	work();
	puts("yes");
	for(int i = 1 ; i < N << 1 ; ++i)
		printf("%d " , num[i]);
	return 0;
}