#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int P = 1e9 + 7; int N , M , fa[500003]; int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

int main(){
	N = read(); M = read(); for(int i = 1 ; i <= M ; ++i) fa[i] = i;
	vector < int > ans; int cnt = 1;
	for(int i = 1 ; i <= N ; ++i){
		int x = read() , x1 = read() , x2 = 0; if(x == 2) x2 = read();
		if(find(x1) != find(x2)){cnt = (cnt * 2) % P; ans.push_back(i); fa[find(x1)] = find(x2);}
	}
	cout << cnt << ' ' << ans.size() << endl; for(auto t : ans) cout << t << ' ';
	return 0;
}