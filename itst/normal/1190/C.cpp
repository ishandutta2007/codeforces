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
	static int arr[100003];
	int N = read() , K = read();
	for(int i = 1 ; i <= N ; ++i){
		char c = getchar();	
		while(!isdigit(c)) c = getchar();
		arr[i] = c - '0';
	}
	int pos = 1;
	while(pos <= N && arr[pos] == arr[1]) ++pos;
	if(pos + K - 1 >= N){puts("tokitsukaze"); return 0;}
	pos = N;
	while(pos && arr[pos] == arr[N]) --pos;
	if(pos - K + 1 <= 1){puts("tokitsukaze"); return 0;}
	int lp = 1 , rp = N;
	if(arr[1] == arr[N]){
		while(lp <= N && arr[lp] == arr[1]) ++lp;
		while(rp && arr[rp] == arr[N]) --rp;
		if(rp - lp + 1 <= K){puts("tokitsukaze"); return 0;}
	}
	set < int > cnt0 , cnt1;
	for(int i = K + 1 ; i <= N ; ++i)
		if(arr[i] == 0) cnt0.insert(i);
		else cnt1.insert(i);
	bool flg = 1;
	for(int i = 0 ; flg && i + K <= N ; ++i){
		if(cnt1.empty() || (*--cnt1.end() - *cnt1.begin() + 1 <= K))
			flg &= 1;
		else
			flg = 0;
		if(cnt0.empty() || (*--cnt0.end() - *cnt0.begin() + 1 <= K))
			flg &= 1;
		else
			flg = 0;
		if(arr[i + 1] == 0) cnt0.insert(i + 1);
		else cnt1.insert(i + 1);
		if(i + K + 1 <= N)
			if(arr[i + K + 1] == 0) cnt0.erase(i + K + 1);
			else cnt1.erase(i + K + 1);
	}
	if(flg == 1) puts("quailty");
	else puts("once again");
	return 0;
}