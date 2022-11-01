#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; int nxt[_] , N , cntl[_] , cntr[_] , fl[_] , fr[_]; long long ans = 0;
#define lowbit(x) ((x) & -(x))
int arr[_]; void add(int x , int v){while(x <= 2 * N){arr[x] += v; x += lowbit(x);}}
int qry(int x){int sum = 0; while(x){sum += arr[x]; x -= lowbit(x);} return sum;}

int main(){
	ios::sync_with_stdio(0); cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		int p , q; cin >> p >> q; nxt[p] = q; nxt[q] = p; ++cntl[max(p , q)]; ++cntr[min(p , q)];
	}
	for(int i = 1 ; i <= 2 * N ; ++i) cntl[i] += cntl[i - 1];
	for(int i = 2 * N ; i ; --i) cntr[i] += cntr[i + 1];

	for(int i = 1 ; i <= 2 * N ; ++i)
		if(nxt[i] > i){
			ans += 1ll * cntl[i] * (2 * N - nxt[i]);
			ans -= 1ll * cntr[nxt[i]] * (cntr[nxt[i]] - 1) / 2;
		}

	for(int i = 1 ; i <= 2 * N ; ++i)
		if(i > nxt[i]){
			fl[nxt[i]] = qry(nxt[i]); add(nxt[i] , 1); add(i , -1);
		}
	memset(arr , 0 , sizeof(arr)); int num = 0;
	for(int i = 2 * N ; i ; --i) if(i > nxt[i]){fr[i] = num - qry(nxt[i]); ++num; add(nxt[i] , 1);}
	for(int i = 1 ; i <= 2 * N ; ++i) if(i < nxt[i]) ans += 1ll * fl[i] * fr[nxt[i]];
	
	memset(arr , 0 , sizeof(arr));
	for(int i = 2 * N ; i ; --i)
		if(i < nxt[i]){ans -= 1ll * qry(nxt[i]) * cntr[nxt[i]]; add(i , 1); add(nxt[i] , -1);}
	cout << ans; return 0;
}