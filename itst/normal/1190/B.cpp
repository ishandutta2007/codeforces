#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

#define int long long
int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

signed main(){
#ifndef ONLINE_JUDGE
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	static int arr[100003] , N = read() , sum = 0;
	map < int , int > now;
	for(int i = 1 ; i <= N ; ++i){
		arr[i] = read(); ++now[arr[i]]; sum += arr[i];
		if(now[arr[i]] >= 3){puts("cslnb"); return 0;}
	}
	int cnt = 0;
	for(auto t : now)
		if(t.second == 2 && (now.find(t.first - 1) != now.end() || t.first == 0)){
			puts("cslnb"); return 0;
		}
		else if(t.second == 2 && ++cnt == 2){puts("cslnb"); return 0;}
	for(int i = 0 ; i < N ; ++i) sum -= i;
	puts(sum & 1 ? "sjfnb" : "cslnb");
	return 0;
}