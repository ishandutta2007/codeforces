#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Wall{
	int x1, y1, x2, y2;
};

ll n;
int h, w;
vector<Wall> wll;
ll p3[45];
int d[45];

void f(){
	p3[0] = 1;
	for(int i = 1; i <= 37; i++) p3[i] = p3[i - 1] * 3ll;
	ll t = n;
	for(int i = 37; i >= 0; i--){
		if(t >= p3[i]){
			while(t >= p3[i]){
				d[i]++;
				t -= p3[i];
			}
		}
	}
	h = w = 41;
	for(int i = 4; i <= 40; i++) wll.push_back({i, i - 3, i, i - 2});
	for(int i = 4; i <= 40; i++) wll.push_back({i - 3, i, i - 2, i});
	for(int i = 6; i <= 41; i++) wll.push_back({i, i - 5, i, i - 4});
	for(int i = 6; i <= 41; i++) wll.push_back({i - 5, i, i - 4, i});	
	for(int i = 6; i <= 41; i++) wll.push_back({i - 1, i - 5, i, i - 5});
	for(int i = 6; i <= 41; i++) wll.push_back({i - 5, i - 1, i - 5, i});
	wll.push_back({39, 40, 39, 41});
	wll.push_back({40, 40, 40, 41});
	wll.push_back({40, 39, 41, 39});
	wll.push_back({40, 40, 41, 40});
	for(int i = 0; i <= 37; i++){
		if(d[i] <= 0){
			wll.push_back({i + 1, i + 3, i + 1, i + 4});
		}
		if(d[i] <= 1){
			wll.push_back({i + 3, i + 1, i + 4, i + 1});
		}
	}
}

int main(){
	cin >> n;
	f();
	cout << h << ' ' << w << '\n';
	cout << wll.size() << '\n';
	for(int i = 0; i < wll.size(); i++){
		printf("%d %d %d %d\n", wll[i].x1, wll[i].y1, wll[i].x2, wll[i].y2);
	}
	return 0;
}