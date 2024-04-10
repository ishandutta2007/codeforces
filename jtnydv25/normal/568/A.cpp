#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
const int N = 5e6 + 10;
int factor[N], mu[N], pi[N], npal[N];
inline int rev(int n){
	int res = 0;
	while(n){ res = res * 10 + (n % 10); n /= 10;}
	return res;
}
inline bool pal(int n){ return n == rev(n);}
void pre(){
    for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    npal[1] = 1;
    for(int i = 2;i<N;i++){
    	pi[i] = pi[i - 1];
    	npal[i] = npal[i - 1];
    	if(!factor[i]) factor[i] = i, pi[i] ++;
    	if(pal(i)) npal[i] ++;
    }
  	
}
int main(){
	pre();
	int p, q;
	cin >> p >> q;
	int ans = 0;
	for(int i = N - 1; i >= 1; i --) if((pi[i] * 1ll * q) <= (npal[i] * 1ll * p)) ans = max(ans, i);
	if(ans == 0){
		cout << "Palindromic tree is better than splay tree\n"; return 0;
	}	
	cout << ans;	
}