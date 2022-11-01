#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int sum = 0;
		map<int, int> mp;
		mp[0] = 0;
		int last = 0;
		for(int i = 1;i <= n;i++){
			last++;
			sum ^= a[i];
			if(mp.count(sum)){
				int val = i + mp[sum] - 1;
				last = min(last, val);
				mp[sum] = min(mp[sum], last - i);
			}else{
				mp[sum] = last - i;
			}
		}
		printf("%d\n", last);
	} 
}