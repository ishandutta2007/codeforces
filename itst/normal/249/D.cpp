#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 1e5 + 7;
struct node{int B , C;}c[_]; int N , A , B , C , D , dp[_];

#define lowbit(x) x & -x
int arr[_];
void add(int x , int v){while(x <= N){arr[x] = max(arr[x] , v); x += lowbit(x);}}
int qry(int x){int sum = 0; while(x){sum = max(sum , arr[x]); x -= lowbit(x);} return sum;}
void clr(int x){while(x <= N){arr[x] = 0; x += lowbit(x);}}

signed main(){
	scanf("%lld" , &N); scanf("%lld/%lld %lld/%lld" , &A , &B , &C , &D); vector < int > lc;
	for(int i = 1 , x , y ; i <= N ; ++i){
		scanf("%lld %lld" , &x , &y); int q = y * B - x * A , r = y * D - x * C;
		c[i] = (node){q , r}; lc.push_back(r);
	}
	++N; lc.push_back(0); sort(lc.begin() , lc.end()); lc.resize(unique(lc.begin() , lc.end()) - lc.begin());
	for(int i = 1 ; i <= N ; ++i) c[i].C = lower_bound(lc.begin() , lc.end() , c[i].C) - lc.begin() + 1;
	sort(c + 1 , c + N + 1 , [&](node p , node q){return p.B < q.B || (p.B == q.B && p.C < q.C);});
	for(int i = N ; i ; --i){add(c[i].C , dp[i] = qry(c[i].C - 1) + 1); if(!c[i].B && !lc[c[i].C - 1]){cout << dp[i] - 1; return 0;}}
}