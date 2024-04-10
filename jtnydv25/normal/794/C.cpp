#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vll vector<ll >
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"
const int N = 4e5;
multiset<int> player[2], temp[2];
char ans[N];
int main(){
	string A, B;
	cin.tie(0);
	cin >> A;
	cin >> B;
	int n = A.length();
	int cntb = n / 2;
	int cnta = n - cntb;
	set<int> rem;
	int mna = 26, mxb = -1;
	for(int i = 0; i < n; i++){
		temp[0].insert(A[i] - 'a');
		temp[1].insert(- (B[i] - 'a'));
		rem.insert(i);
	}
	for(int i = 0; i < cnta; i++){
		player[0].insert(*temp[0].begin());
		temp[0].erase(temp[0].begin());
	}
	for(int i = 0; i < cntb; i++){
		player[1].insert(*temp[1].begin());
		temp[1].erase(temp[1].begin());
	}
	// print(player[0]);
	// print(player[1]);
	int turn = 0;
	while(!rem.empty()){
		if(rem.size() == 1){
			ans[*rem.begin()] = 'a' + abs(*player[turn].begin());
			rem.clear();
			continue;
		}
		auto it = rem.begin();
		auto it2 = player[turn].end();
		--it2;

		if(turn == 0){
			if(((*player[0].begin()) >= abs(*player[1].begin()))){
				it = rem.end(); --it;
				ans[*it] = 'a' + (*it2);
				rem.erase(it);
				player[0].erase(it2);
				turn ^= 1; n--;
				continue;
			}
			int ind = *it;
			rem.erase(ind);
			ans[ind] = 'a' + (*player[0].begin());
			player[0].erase(player[0].begin());
		}
		else{
			if((abs(*player[1].begin()) <= (*player[0].begin()))){
				it = rem.end(); --it;
				ans[*it] = 'a' + abs(*it2);
				rem.erase(it);
				player[1].erase(it2);
				turn ^= 1; n--;
				continue;
			}
			int ind = *it;
			rem.erase(ind);
			ans[ind] = 'a' + abs(*player[1].begin());
			player[1].erase(player[1].begin());
		}
		turn ^= 1; n--;
	}
	cout << ans;
}