#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<cassert>
//This code is written by Itst
using namespace std;

int read(){
	int a = 0; bool f = 0;
	char c = getchar();
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

#define int long long 
const int _ = 3e5 + 3;
int s[_] , t[_] , id1[_] , id2[_] , N , stp[_ * 5 + 1][3] , cnt;
bool cmp1(int a , int b){return s[a] < s[b];}
bool cmp2(int a , int b){return t[a] < t[b];}

signed main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		s[i] = read();
		id1[i] = id2[i] = i;
	}
	int sum = 0;
	for(int i = 1 ; i <= N ; ++i){
		t[i] = read();
		sum += t[i] - s[i];
	}
	if(sum != 0){puts("NO"); return 0;}
	sort(id1 + 1 , id1 + N + 1 , cmp1);
	sort(id2 + 1 , id2 + N + 1 , cmp2);
	if(s[id1[1]] > t[id2[1]] || s[id1[N]] < t[id2[N]]){puts("NO"); return 0;}
#define PII pair < int , int >
	priority_queue < PII > q1;
	for(int i = 1 ; i <= N ; ++i){
		int sum = s[id1[i]] - t[id2[i]];
		if(sum < 0)
			q1.push(PII(-sum , id1[i]));
		else{
			while(sum && !q1.empty()){
				PII t = q1.top(); q1.pop();
				++cnt; stp[cnt][0] = t.second; stp[cnt][1] = id1[i]; stp[cnt][2] = min(sum , t.first);
				sum -= stp[cnt][2]; t.first -= stp[cnt][2];
				if(t.first) q1.push(t);
			}
			if(sum){
				puts("NO"); return 0;
			}
		}
	}
	if(q1.size()){puts("NO"); return 0;}
	assert(cnt <= 5 * N);
	cout << "YES\n" << cnt << endl;
	for(int i = 1 ; i <= cnt ; ++i)
		cout << stp[i][0] << ' ' << stp[i][1] << ' ' << stp[i][2] << endl;
	return 0;
}