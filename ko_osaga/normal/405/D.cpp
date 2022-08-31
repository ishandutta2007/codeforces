#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, chk[1000005];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		chk[x] = 1;
	}
	int cnt = 0;
	vector<int> v;
	for(int i=1; i<=1000000; i++){
		if(!chk[i]) continue;
		if(chk[1000001-i] != 0){
			cnt++;
		}
		else{
			v.push_back(1000001-i);
		}
	}
	for(int i=1; i<=1000000; i++){
		if(cnt > 0 && !chk[i] && !chk[1000001-i]){
			v.push_back(i);
			v.push_back(1000001-i);
cnt -= 2;
		}
	}
	printf("%d\n", v.size());
	for(auto &i : v){
		printf("%d ", i);
	}
}