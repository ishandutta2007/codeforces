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

#define PII pair < int , int >
const int _ = 1e5 + 7 , MOD = 1e9 + 7 , MOD2 = 1e9 + 9;
priority_queue < PII > q;
vector < PII > Edge[_];
int logg10[_] , dis[_] , N , M , jump[_][20] , val[_] , ans[_]; long long faid[_];

int gethash(int x , int len , int id){
	int now;
	if(len > dis[x]){now = val[x]; len -= dis[x];}
	else{
		for(int i = 19 ; i >= 0 ; --i) if(dis[jump[x][i]] >= len) x = jump[x][i];
		now = val[jump[x][0]]; len -= dis[jump[x][0]]; id = faid[x];
	}
	while(logg10[id] != len - 1) id /= 10;
	for(int i = 0 ; i < len ; ++i) now = 1ll * now * 10 % MOD2;
	return (now + id) % MOD2;
}

int getch(int x , int len , int id){
	if(len > dis[x]) len -= dis[x];
	else{
		for(int i = 19 ; i >= 0 ; --i) if(dis[jump[x][i]] >= len) x = jump[x][i];
		len -= dis[jump[x][0]]; id = faid[x];
	}
	while(logg10[id] != len - 1) id /= 10;
	return id % 10;
}

bool cmp(int p , int q , int idp , int idq){
	if(!p) return 1;
	int L = 1 , R = logg10[idp] + 1 + dis[p];
	while(L < R){
		int mid = (L + R) >> 1;
		gethash(p , mid , idp) != gethash(q , mid , idq) ? R = mid : L = mid + 1;
	}
	return getch(p , L , idp) > getch(q , L , idq);
}

void done(int x , int pre , int nid){
	ans[x] = ans[pre]; for(int i = 0 ; i <= logg10[nid] ; ++i) ans[x] = ans[x] * 10ll % MOD;
	val[x] = val[pre]; for(int i = 0 ; i <= logg10[nid] ; ++i) val[x] = val[x] * 10ll % MOD2;
	ans[x] = (ans[x] + nid) % MOD; val[x] = (val[x] + nid) % MOD2;

	faid[x] = nid; jump[x][0] = pre;
	for(int i = 1 ; jump[x][i - 1] ; ++i) jump[x][i] = jump[jump[x][i - 1]][i - 1];
}

void dijk(){
	memset(dis , 0x3f , sizeof(dis)); dis[0] = dis[1] = 0; q.push(PII(0 , 1));
	while(!q.empty()){
		PII t = q.top(); q.pop();
		if(dis[t.second] != -t.first) continue;

		int now = 0 , nid = 0;
		for(auto p : Edge[t.second])
			if(dis[p.first] + logg10[p.second] + 1 == dis[t.second])
				if(cmp(now , p.first , nid , p.second)){
					now = p.first; nid = p.second;
				}
		
		if(now) done(t.second , now , nid);
		
		for(auto p : Edge[t.second])
			if(dis[p.first] > dis[t.second] + logg10[p.second] + 1){
				dis[p.first] = dis[t.second] + logg10[p.second] + 1;
				q.push(PII(-dis[p.first] , p.first));
			}
	}
}

int main(){
	N = read(); M = read(); logg10[0] = -1;
	for(int i = 1 ; i <= M ; ++i) logg10[i] = logg10[i / 10] + 1;
	for(int i = 1 ; i <= M ; ++i){
		int p = read() , q = read();
		Edge[p].push_back(PII(q , i)); Edge[q].push_back(PII(p , i));
	}
	dijk();
	for(int i = 2 ; i <= N ; ++i) printf("%d\n" , ans[i]);
	return 0;
}