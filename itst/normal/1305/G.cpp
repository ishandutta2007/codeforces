#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 1 << 18;
int fa[_] , cnt[_] , sz[_] , N; long long sum = 0;
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

int main(){
	N = read(); ++cnt[0]; for(int x , i = 1 ; i <= N ; ++i){x = read(); ++cnt[x]; sum -= x;}
	for(int i = 0 ; i < _ ; ++i){fa[i] = i; sz[i] = 1;}
	for(int i = _ - 1 ; i ; --i){
		int s = i;
		do{
			if(cnt[s] && cnt[i ^ s]){
				int p = find(s) , q = find(i ^ s); if(p == q) continue;
				sum += 1ll * (cnt[p] + cnt[q] - 1) * i; if(sz[p] > sz[q]) swap(p , q);
				fa[p] = q; cnt[q] = 1; sz[q] += sz[p];
			}
		}while(s = (s - 1) & i);
	}
	cout << sum; return 0;
}