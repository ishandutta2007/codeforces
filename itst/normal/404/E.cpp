#include<bits/stdc++.h>
using namespace std;
 
const int _ = 1e6 + 7;
char str[_];
	
int main(){
	scanf("%s" , str + 1); int L = strlen(str + 1);
	for(int i = 1 ; i <= L ; ++i) str[i] = '0' + (str[i] == 'R');
	if(str[L] == '0') for(int i = 1 ; i <= L ; ++i) str[i] ^= 1;
	int l = 0 , r = L + 1;
	while(l < r){
		int mid = ((l + r + 1) >> 1) , mx = 0 , cur = 0;
		for(int j = 1 ; j < L ; ++j) mx = max(mx , cur = max(-mid + 1 , cur + 1 - (str[j] == '0') * 2));
		cur == mx ? l = mid : r = mid - 1;
	}
	printf("%d\n" , l == L + 1 ? 1 : l);
	return 0;
}