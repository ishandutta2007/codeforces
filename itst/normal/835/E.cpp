#include<bits/stdc++.h>
using namespace std;

int N , X , Y;
bool dif[15];

vector < int > pot;
int ask1(int id){
	pot.clear();
	for(int i = 1 ; i <= N ; ++i)
		if(i >> id & 1) pot.push_back(i);
	cout << "? " << pot.size() << ' ';
	for(int i = 0 ; i < pot.size() ; ++i) cout << pot[i] << ' ';
	cout << endl;
	int val; cin >> val; return val;
}

vector < int > now;
int ask2(int id){
	cout << "? " << id << ' ';
	for(int i = 0 ; i < id ; ++i) cout << now[i] << ' ';
	cout << endl;
	int val; cin >> val; return val;
}

int main(){
	cin >> N >> X >> Y;
	for(int i = 0 ; 1 << i <= N ; ++i)
		dif[i] = ask1(i) != (pot.size() & 1 ? X : 0);
	for(int i = 0 ; 1 << i <= N ; ++i)
		if(dif[i]){
			for(int j = 1 ; j <= N ; ++j)
				if(j >> i & 1) now.push_back(j);
			break;
		}
	int L = 0 , R = now.size() - 1;
	while(L < R){
		int mid = (L + R) >> 1;
		ask2(mid + 1) != (mid & 1 ? 0 : X) ? R = mid : L = mid + 1;
	}
	int ans1 = now[L] , ans2 = ans1;
	for(int i = 0 ; 1 << i <= N ; ++i)
		if(dif[i]) ans2 ^= 1 << i;
	if(ans1 > ans2) swap(ans1 , ans2);
	cout << "! " << ans1 << ' ' << ans2 << endl;
	return 0;
}