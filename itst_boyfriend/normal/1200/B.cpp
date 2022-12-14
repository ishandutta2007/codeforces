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

int main(){
	int T; cin >> T;
	while(T--){
		static int arr[103] , N , M , K;
		cin >> N >> M >> K; bool flg = 1;
		for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
		for(int j = 2 ; j <= N ; ++j)
			if(arr[j] - arr[j - 1] <= K)
				M += arr[j - 1] - max(0 , arr[j] - K);
			else{
				flg &= M >= arr[j] - arr[j - 1] - K;
				M -= arr[j] - arr[j - 1] - K;
			}
		puts(flg ? "YES" : "NO");
	}
	return 0;
}