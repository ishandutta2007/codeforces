#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

int main(){
	int a, b;
	cin >> a >> b;
	for(int x = 1; x < a; x++){
		for(int y = 1; y < a; y++){
			if(x * x + y * y == a * a){
				if((b * y) % a == 0 && (b * x) % a == 0){
					int x1 = - (b * y) / a;
					int y1 = (b * x) / a;
					if(y1 != y){
						cout << "YES\n0 0\n" << x << " " << y << "\n" << x1 << " " << y1;
						return 0;
					}
				}
			}
		}
	}
	cout << "NO\n"; 
}