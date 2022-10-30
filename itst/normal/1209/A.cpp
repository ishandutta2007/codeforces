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

set < int > num;

int main(){
	int N , cnt = 0; cin >> N;
	for(int i = 1 ; i <= N ; ++i){int a; cin >> a; num.insert(a);}
	while(!num.empty()){
		++cnt; int val = *num.begin();
		for(int i = val ; i <= 100 ; i += val)
			if(num.find(i) != num.end()) num.erase(i);
	}
	cout << cnt;
	return 0;
}