//O(n^2/w+nc)
#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

#define ull unsigned long long
const int _ = 1e5 + 11; vector < int > nxt[_][2]; int N , C[_] , ans; long long num;
void addEd(int a , int b , int c){nxt[a][c].push_back(b);}

int deg[_] , dst[_] , seq[_] , cseq; ull arr[_][50];
void build(int fir){
	memset(deg , 0 , sizeof(deg)); cseq = 0;
	for(int i = 1 ; i <= N + 8 ; ++i){
		for(auto t : nxt[i][0]) deg[t] += dst[t] == dst[i];
		for(auto t : nxt[i][1]) deg[t] += dst[t] == dst[i] + 1;
	}
	queue < int > q; q.push(fir);
	while(!q.empty()){
		int t = q.front(); q.pop(); seq[++cseq] = t;
		for(int l = 0 ; l < 2 ; ++l) for(auto p : nxt[t][l]) if(dst[p] == dst[t] + l && !--deg[p]) q.push(p);
	}
}
void solve(int size , vector < int > node , int fir , int mx){
	memset(arr , 0 , sizeof(arr)); for(int i = 0 ; i < node.size() ; ++i) arr[node[i]][i >> 6] |= 1ull << (i & 63);
	for(int i = 1 ; i <= cseq ; ++i){
		int t = seq[i];
		for(int l = 0 ; l < 2 ; ++l)
			for(auto p : nxt[t][l]) if(dst[p] == dst[t] + l) for(int r = 0 ; r < 50 ; ++r) arr[p][r] |= arr[t][r];
	}
	long long cnt = 0; int val = node.size();
	for(int i = 1 ; i <= N && val == node.size() ; ++i)
		if(dst[i] == mx){int num = 0; for(int j = 0 ; j < 50 ; ++j){num += __builtin_popcountll(arr[i][j]);} val = min(val , num);}
	if(val == node.size()) --mx;
	for(int i = 1 ; i <= N ; ++i)
		if(dst[i] > mx) cnt += node.size();
		else if(dst[i] == mx){int num = 0; for(int j = 0 ; j < 50 ; ++j){num += __builtin_popcountll(arr[i][j]);} cnt += node.size() - num;}
	if(ans < mx){ans = mx; num = 0;} if(ans == mx) num += cnt;
}

int main(){
	ios::sync_with_stdio(0); cin >> N; for(int i = 1 ; i <= N ; ++i){char c; cin >> c; C[i] = c - 'a' + 1; addEd(i , N + C[i] , 0); addEd(N + C[i] , i , 1);}
	for(int i = 2 ; i <= N ; ++i){addEd(i - 1 , i , 1); addEd(i , i - 1 , 1);}
	for(int i = 1 ; i <= 8 ; ++i){
		memset(dst , 0x3f , sizeof(dst)); dst[N + i] = 0; deque < int > q; q.push_back(N + i); int mx = 0;
		while(!q.empty()){
			int t = q.front(); q.pop_front(); if(t <= N) mx = max(mx , dst[t]);
			for(auto r : nxt[t][0]) if(dst[r] > dst[t]){dst[r] = dst[t]; q.push_front(r);}
			for(auto r : nxt[t][1]) if(dst[r] > dst[t] + 1){dst[r] = dst[t] + 1; q.push_back(r);}
		}
		vector < int > node; build(N + i);
		for(int j = 1 ; j <= N ; ++j) if(C[j] == i){node.push_back(j); if(node.size() == 64 * 50){solve(64 * 50 , node , N + i , mx); node.clear();}}
		if(node.size()) solve(node.size() , node , N + i , mx);
	}
	cout << ans << ' ' << num / 2; return 0;
}