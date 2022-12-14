#include<bits/stdc++.h>
using namespace std;

int T , N; long long A[200003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		for(int i = 1 ; i < N ; ++i) A[i] = A[i] < A[i + 1] ? A[i + 1] - A[i] : A[i] - A[i + 1];
		vector < pair < int , long long > > pot; int ans = 1; pot.push_back(make_pair(1 , 0));
		for(int i = 2 ; i <= N ; ++i){
			vector < pair < int , long long > > temp; int pre = -1; long long v = A[i - 1];
			while(pot.size()){
				int p = pot.back().first; long long r = __gcd(pot.back().second , v);
				if(r != v && pre != -1) temp.push_back(make_pair(pre , v));
				v = r; pre = p; pot.pop_back();
			}
			temp.push_back(make_pair(pre , v)); reverse(temp.begin() , temp.end());
			temp.push_back(make_pair(i , 0)); ans = max(ans , i - (temp[0].second != 1 ? 1 : temp[1].first) + 1);
			pot = temp;
		}
		cout << ans << '\n';
	}
	return 0;
}