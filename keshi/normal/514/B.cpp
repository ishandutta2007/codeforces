#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, m;
pair<double, double> a, b[1100];
bool dead[1100];

int main(){
	cin >> n >> a.x >> a.y;
	for(int i = 0; i < n; i++){
		cin >> b[i].x >> b[i].y;
	}
	for(int i = 0; i < n; i++){
		if(!dead[i]){
			for(int j = i; j < n; j++){
				if( (b[i].x - a.x) * (b[j].y - a.y) == (b[j].x - a.x) * (b[i].y - a.y)){
					dead[j] = 1;
				}
			}
			m++;
		}
	}
	cout << m;
	return 0;
}