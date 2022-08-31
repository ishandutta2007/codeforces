#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, s, a[200005];
int cnt[200005];

int main(){
	scanf("%d %d",&n,&s);
	int ret = 0, bad = 0 ;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(s == i){
			if(a[i] != 0) a[i] = 0, ret++;
		}
		else{
			if(a[i] == 0) bad++, ret++;
			else cnt[a[i]]++;
		}
	}
	int endp = n-1;
	while(endp > 0 && cnt[endp] == 0) endp--;
	for(int i=1; i<endp; i++){
		if(cnt[i] == 0){
			if(!bad){
				cnt[endp]--;
				ret++;
				while(endp > 0 && cnt[endp] == 0) endp--;
				bad++;
			}
			cnt[i]++;
			bad--;
		}
	}
	cout << ret;
}