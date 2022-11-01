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

const int _ = 2e5 + 3;
int arr[_] , f[_] , nxt[_] , sz[_] , N , Q , ans;
vector < int > ch[_];

int main(){
	N = read(); 
	Q = read();
	for(int i = 1 ; i <= N ; ++i) ++sz[arr[i] = read()];
	set < int > in; int cnt = 0 , tar = 0;
	for(int i = 1 ; i <= N ; ++i){
		if(in.find(arr[i]) == in.end()){
			in.insert(arr[i]); tar += sz[arr[i]];
		}
		if(tar == ++cnt){
			int mx = 0;
			for(auto t : in) mx = max(mx , sz[t]);
			ans += tar - mx; in.clear(); cnt = 0; tar = 0; 
		}
	}
	cout << ans;
	return 0;
}