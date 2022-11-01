#include<bits/stdc++.h>
using namespace std;

long long pre[200003] , dp[200003]; int N , K , A[200003];

long long cnt; int num[200003] , pl = 1 , pr;
void add(int x){cnt += num[x]++;} void del(int x){cnt -= --num[x];}
void move(int tl , int tr){
	while(pl > tl) add(A[--pl]);
	while(pr < tr) add(A[++pr]);
	while(pl < tl) del(A[pl++]);
	while(pr > tr) del(A[pr--]);
}

void solve(int l , int r , int L , int R){
	if(l > r) return;
	int mid = (l + r) >> 1; long long mn = 1e18; int id = 0;
	for(int i = L ; i <= R && i < mid ; ++i){move(i + 1 , mid); if(mn > cnt + pre[i]){mn = cnt + pre[i]; id = i;}}
	dp[mid] = mn; solve(l , mid - 1 , L , id); solve(mid + 1 , r , id , R);
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> K; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	memset(pre , 0x3f , sizeof(pre)); pre[0] = 0;
	for(int i = 1 ; i <= K ; ++i){solve(i , N , i - 1 , N - 1); memcpy(pre , dp , sizeof(dp));}
	cout << dp[N]; return 0;
}