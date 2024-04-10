#include<bits/stdc++.h>
using namespace std;

#define int long long
struct vec{
	int x , y; long double ang;
	vec(int _x = 0 , int _y = 0) : x(_x) , y(_y){ang = atan2(y , x);}
	friend vec operator +(vec x , vec y){return vec(x.x + y.x , x.y + y.y);}
	friend vec operator -(vec x , vec y){return vec(x.x - y.x , x.y - y.y);}
	friend int operator *(vec x , vec y){return x.x * y.x + x.y * y.y;}
	friend int operator %(vec x , vec y){return x.x * y.y - x.y * y.x;}
	friend bool operator <(vec x , vec y){return x.ang < y.ang;}
};
int X[2503] , Y[2503] , Choose[2503] , Choose1[2503] , N;

signed  main(){
	cin >> N; int ans = 0;
	for(int i = 1 ; i <= N ; ++i) cin >> X[i] >> Y[i];
	for(int i = 0 ; i <= N ; ++i){
		Choose1[i] = i * (i - 1) / 2 * (i - 2) / 3;
		Choose[i] = i * (i - 1) / 2 * (i - 2) / 3 * (i - 3) / 4;
	}
	for(int i = 1 ; i <= N ; ++i){
		vector < vec > now; int tmp = Choose[N - 1];
		for(int j = 1 ; j <= N ; ++j)
			if(i != j) now.push_back(vec(X[j] - X[i] , Y[j] - Y[i]));
		sort(now.begin() , now.end());
		int pos = -1 , sz = now.size(); now.insert(now.end() , now.begin() , now.end());
		for(int j = 0 ; j < sz ; ++j){
			while(pos - j + 1 < sz && (now[j] % now[pos + 1]) >= 0)
				++pos;
			tmp -= Choose1[pos - j];
		}
		ans += tmp;
	}
	cout << ans; return 0;
}