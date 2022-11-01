#include<bits/stdc++.h>
using namespace std;

/*
  REMEMBER:
  1.Think TWICE, code ONCE!
  Are there any counterexamples to your algo?
	
  2.Be careful about the BOUNDARIES in your algo!
  N=1? P=1? Is P a prime? Something about 0?
	
  3.Never make STUPID MISTAKES!
  Integer overflow? Array size? Time complexity? Memory usage? Precition error?
*/

#define int long long
const int _ = 4e5 + 7;
int arr[_] , tsh[_] , peo[_] , sum[_] , N , C , ans;

#define PII pair < int , int >
#define lch (x << 1)
#define rch (x << 1 | 1)
#define mid ((l + r) >> 1)
int mn[_ << 2];
void ins(int x , int l , int r , int tar , int val){
	if(l == r) mn[x] = val;
	else{
		mid >= tar ? ins(lch , l , mid , tar , val) : ins(rch , mid + 1 , r , tar , val);
		mn[x] = min(mn[lch] , mn[rch]);
	}
}

int qry(int x , int l , int r , int L , int R){
	if(l >= L && r <= R) return mn[x];
	int now = 1e9;
	if(mid >= L) now = qry(lch , l , mid , L , R);
	if(mid < R) now = min(now , qry(rch , mid + 1 , r , L , R));
	return now;
}
#undef mid

PII calc(int l , int r){
	if(l > r) return PII(0 , 0);
	int s1 = sum[r] - sum[l - 1] , s2 = sum[r] - qry(1 , 0 , N , l - 1 , r);
	return PII(s2 , s2 - s1);
}

signed main(){
	cin >> N >> C; for(int i = 1 ; i < 2 * N ; ++i) cin >> arr[i];
	for(int i = 1 ; i <= N ; ++i){
		if(i == 1) tsh[i] = min(arr[1] , C);
		else if(arr[2 * i - 1] >= C) tsh[i] = C;
		else{
			int L = 1 , R = i - 1;
			while(L < R){
				int mid = (L + R + 1) >> 1;
				peo[i - 1] - peo[mid - 1] >= C - arr[2 * i - 1] ? L = mid : R = mid - 1;
			}
			PII t = calc(L + 1 , i - 1); int num = C - (peo[i - 1] - peo[L]) - arr[2 * i - 1];
			if(L == 1) num = min(num , peo[1]);
			tsh[i] = arr[2 * i - 1] + t.first + max(0ll , num - tsh[L] - t.second);
		}
		ans += tsh[i]; peo[i] = arr[2 * i - 1] + arr[2 * i] + peo[i - 1];
		sum[i] = sum[i - 1] + (arr[2 * i - 1] + arr[2 * i] - tsh[i]);
		//cerr << tsh[i] << endl;
		ins(1 , 0 , N , i , sum[i]);
	}
	cout << ans; return 0;
}