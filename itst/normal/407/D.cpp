#include<bits/stdc++.h>
using namespace std;

#define PII pair < int , int >
int arr[403][403] , lft[403][403] , rht[403][403] , R[403] , app[160003] , cnt[160003] , N , M , ans;
deque < PII > q1 , q2; 

void push1(PII val){
	if(val.first == 0) return;
	if(!q1.empty() && q1.back().first >= val.first) return;
	q1.push_back(val);
}

void push2(PII val){
	if(val.second == 0x3f3f3f3f - 1) return;
	while(!q2.empty() && q2.back().second >= val.second) q2.pop_back();
	q2.push_back(val);
}

int getmn(deque < PII > &q , int bd){
	while(!q.empty() && q.front().first < bd) q.pop_front();
	return q.empty() ? 1e9 : q.front().second;
}

int main(){
	cin >> N >> M; for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= M ; ++j) cin >> arr[i][j];
	for(int i = N ; i ; --i){
		for(int j = 1 ; j <= M ; ++j) R[j] = M;
		memset(app , 0 , sizeof(app));
		for(int j = 1 ; j <= M ; ++j){
			lft[i][j] = app[arr[i][j]]; app[arr[i][j]] = j;
			for(int k = i + 1 ; k <= N ; ++k) lft[k][j] = max(lft[k][j] , app[arr[k][j]]);
		}
		memset(app , 0x3f , sizeof(app));
		for(int j = M ; j ; --j){
			rht[i][j] = app[arr[i][j]]; app[arr[i][j]] = j;
			for(int k = i + 1 ; k <= N ; ++k) rht[k][j] = min(rht[k][j] , app[arr[k][j]]);
		}
		for(int j = i ; j <= N ; ++j){
			q1.clear(); q2.clear(); int pos = 0;
			for(int k = 1 ; k <= M ; ++k){
				while(pos < R[k]){++pos; push1(PII(lft[j][pos] , pos - 1)); push2(PII(pos , rht[j][pos] - 1));}
				R[k] = min(min(getmn(q1 , k) , getmn(q2 , k)) , R[k]);
				ans = max(ans , (R[k] - k + 1) * (j - i + 1));
			}
		}
	}
	cout << ans; return 0;
}