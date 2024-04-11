#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int che[10000005];
int ovr[10000005];

lint solve(lint x, int c){
	lint ret = 0;
	while(x){
		ret += x / c;
		x /= c;
	}
	return ret;
}

int main(){
	for(int i=2; i<=10000000; i++){
		if(che[i]) continue;
		for(int j=2*i; j<=10000000; j+=i){
			che[j] = 1;
		}
	}
	int n;
	cin >> n;
	while(n--){
		int x;
		scanf("%d",&x);
		ovr[x]++;
	}
	for(int i=10000000; i>=1; i--){
		ovr[i] += ovr[i+1];
	}
	lint ret = 1;
	for(int i=2; i<=10000000; i++){
		if(che[i]) continue;
		lint cnt = 0;
		for(lint j=i; j<=10000000; j*=i){
			for(int k=j; k<=10000000; k+=j){
				cnt += ovr[k];
			}
		}
		lint s = 0, e = 1e13;
		while(s != e){
			lint m = (s+e)/2;
			if(solve(m, i) >= cnt) e = m;
			else s = m+1;
		}
		ret = max(ret, s);
	}
	cout << ret;
}