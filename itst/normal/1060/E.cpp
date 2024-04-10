#include<bits/stdc++.h>
#define MAXN 200010
#define int long long
using namespace std;

struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
long long head[MAXN] , size[MAXN] , N , minSize , minDir , nowSize , cntEd;
long long ans;
bool vis[MAXN];

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
 	Ed[cntEd].upEd = head[a];
 	head[a] = cntEd;
}

void getNowSize(int dir){
 	vis[dir] = 1;
 	nowSize++;
 	for(int i = head[dir] ; i ; i = Ed[i].upEd)
 		if(!vis[Ed[i].end])
			getNowSize(Ed[i].end);
	vis[dir] = 0;
}

void getZX(int dir){
	vis[dir] = size[dir] = 1;
	int maxSize = 0;
	for(int i = head[dir] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){
			getZX(Ed[i].end);
			size[dir] += size[Ed[i].end];
			maxSize = max(maxSize , size[Ed[i].end]);
		}
	maxSize = max(maxSize , nowSize - size[dir]);
	if(maxSize < minSize){
		minSize = maxSize;
		minDir = dir;
	}
	vis[dir] = 0;
}

pair < long long , long long > calAns(int dir , int dep){
	vis[dir] = 1;
	ans += dep + 1 >> 1;
	nowSize++;
	pair < long long , long long > q = make_pair(dep , dep & 1);
	for(int i = head[dir] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){
			pair < long long , long long > t = calAns(Ed[i].end , dep + 1);
			q.first += t.first;
			q.second += t.second;
		}
	vis[dir] = 0;
	return q;
}

void work(int dir){
	nowSize = 0;
	getNowSize(dir);
	minSize = nowSize;
	getZX(dir);
	long long t = minDir , sum = 0 , culJi = 0 , culOu = 0;
	vis[t] = 1;
	nowSize = 0;
	for(int i = head[t] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){
			int k = nowSize;
			pair < long long , long long > t = calAns(Ed[i].end , 1);
			ans += (sum * (nowSize - k) + t.first * k + t.second * culOu + culJi * (nowSize - k - t.second)) >> 1;
			sum += t.first;
			culJi += t.second;
			culOu += nowSize - k - t.second;
		}
	for(int i = head[t] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end])
			work(Ed[i].end);
}

signed main(){
  ios::sync_with_stdio(0);
	cin >> N;
	for(int i = 1 ; i < N ; i++){
		int a , b;
		cin >> a >> b;
		addEd(a , b);
		addEd(b , a);
	}
	work(1);
	cout << ans;
	return 0;
}