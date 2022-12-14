#include<bits/stdc++.h>
using namespace std;

int N , C[100003]; unsigned long long ans;
void calc(int l , int r){
	if(l + 1 == r){ans += min(C[l] , -C[r]); return;}
	long long sum = 0 , mn = 1e18; vector < int > mnpos;
	for(int i = l ; i < r ; ++i){sum += C[i]; if(mn > sum){mn = sum; mnpos = {i};} else if(mn == sum){mnpos.push_back(i);}}
	long long sum1 = max(0ll , sum + C[r]);
	ans += max(mn - sum1 , 0ll) + 1ll * mnpos.size() * (mnpos.size() + (sum1 <= mn ? 1 : -1)) / 2; C[l] -= mn; int pre = l;
	for(auto t : mnpos){calc(pre , t); pre = t + 1;} calc(pre , r);
}

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i){cin >> C[i]; if(!(i & 1)) C[i] = -C[i];}
	if(N & 1) --N; 
	long long sum = 0 , mn = 1e18; int pre = 1;
	for(int i = 1 ; i <= N ; ++i){sum += C[i]; if(sum < 0){sum = 0; calc(pre , i); pre = i + 1; mn = 1e18;}else mn = min(mn , sum);}
	if(pre != N + 1){calc(pre , N);}
	cout << ans; return 0;
}