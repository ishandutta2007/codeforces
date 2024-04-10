#include<bits/stdc++.h>
using namespace std;

int tmp[100003] , N;
vector < pair < int , int > > now;
namespace BIT{
#define lowbit(x) ((x) & -(x))
	int arr[1000003];
	void add(int x , int val){while(x <= 1e6 + 1){arr[x] += val; x += lowbit(x);}}
	int qry(int x){int sum = 0; while(x){sum += arr[x]; x -= lowbit(x);} return sum;}
}

int main(){
	cin >> N; long long ans = N * (N - 1ll);
	for(int l , i = 1 ; i <= N ; ++i){
		cin >> l;
		for(int j = 1 ; j <= l ; ++j) cin >> tmp[j];
		bool flg = 1;
		for(int j = 2 ; j <= l ; ++j) flg &= tmp[j] <= tmp[j - 1];
		if(flg) now.push_back(make_pair(tmp[l] , tmp[1]));
		if(!flg || tmp[l] != tmp[1]) ++ans;
	}
	sort(now.begin() , now.end());
	vector < pair < int , int > > pot; int cnt = 0;
	for(int i = 0 ; i < now.size() ; ++i){
		if(now[i].first != now[i].second || i == 0 || now[i].first != now[i - 1].first || now[i].second != now[i - 1].second){
			ans -= 1ll * cnt * (cnt - 1) / 2; cnt = 0;
		}
		pot.push_back(now[i]);
		++cnt;
	}
	if(cnt) ans -= 1ll * cnt * (cnt - 1) / 2;
	for(int i = 0 ; i < pot.size() ; ++i){
		ans -= BIT::qry(pot[i].first + 1);
		BIT::add(pot[i].second + 1 , 1);
	}
	cout << ans;
	return 0;
}