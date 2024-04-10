#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 10;

ll a[MAXN];
map<ll, ll> s;

int main(){
	int n;
	cin>>n;
	ll inf = 0;
	for(int i = 1; i <= n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = (ll)x * x * y;
		inf = max(inf, a[i]);
	}
	s.clear();
	s[0] = 0;
	for(int i = 1; i <= n; i++){
		auto Nico = s.lower_bound(a[i]);
		ll tmp = 0;
		if (Nico != s.end() && Nico->first == a[i]){
			tmp = Nico->second;
		}
		Nico--;
		if (tmp < Nico->second + a[i]){
			s[a[i]] = Nico->second + a[i];
			Nico++;
			auto Umi = Nico;
			Umi++;
			auto Maki = Umi;
			while(Umi != s.end() && Umi->second <= Nico->second){
				Maki++;
				s.erase(Umi);
				Umi = Maki;
			}
		}
	//	cout<<"############"<<i<<endl;
	//	for(auto j = s.begin(); j != s.end(); j++)
	//		cout<<(j -> first)<<' '; cout<<endl;
	}
	ll ans = 0;
	for(auto j = s.begin(); j != s.end(); j++)
		ans = max(ans, (*j).second);
	printf("%.20lf\n", ans * acos(-1));
	return 0;
}