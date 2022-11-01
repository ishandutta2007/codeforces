#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int _ = 1e5 + 7; int N , K , R;
int query(int x){cout << "? " << x << endl; ++R; int ans; cin >> ans; return ans;}
void getanswer(int x){cout << "! " << x << endl; exit(0);}

void qanswer(int l , int r){while(l < r){int mid = (l + r + 1) >> 1; query((mid + R - 1) % N + 1) != K ? l = mid : r = mid - 1;} getanswer(l);}

int main(){
	cin >> N >> K; query(1);
	if(N <= 100){
		for(int i = 1 ; i <= N / 2 ; ++i){int t = query(1); if(t != K) getanswer(t < K ? 1 + i : N - i + 1);}
		if(N % 2) getanswer(1); else{int t = query(2); t > K ? getanswer(1) : getanswer(N / 2 + 1);}
	}else{
		int t = query(1); if(t != K) getanswer(t < K ? 2 : N);
		t = query(2); if(t != K) t > K ? getanswer(1) : qanswer(3 , 4);
		int cur = 4; while((t = query(cur)) == K){cur += R - 1;}
		qanswer(cur + 1 , min(N - 1 , cur + R));
	}
	return 0;
}