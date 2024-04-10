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

const int _ = 1e5 + 7;
struct thing{int A , B , id; friend bool operator <(thing p , thing q){return p.B > q.B || p.B == q.B && p.A < q.A;}}now[_];
struct cmp{bool operator ()(int a , int b){return now[a].A < now[b].A || now[a].A == now[b].A && now[a].B < now[b].B;}};
priority_queue < int , vector < int > , cmp > q; int N , K , P; vector < int > ans;

int main(){
	N = read(); K = read(); P = read();
	for(int i = 1 ; i <= N ; ++i){now[i].A = read(); now[i].B = read(); now[i].id = i;}
	sort(now + 1 , now + N + 1); for(int i = 1 ; i <= N - (K - P) ; ++i) q.push(i);
	for(int i = 1 ; i <= P ; ++i){ans.push_back(q.top()); q.pop();}
	sort(ans.begin() , ans.end()); int mx = *ans.rbegin();
	for(int i = mx + 1 ; i <= mx + K - P ; ++i) ans.push_back(i);
	for(auto t : ans) printf("%d " , now[t].id);
	return 0;
}