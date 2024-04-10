#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(int a,int b,int c,int x){
	int co = 0;
	x--;
	while(true){
		x++;
		if(x % 7 == 0 || x%7==3 || x%7==6){
			if (a < 1){
				break;
			}
			else{
				a --;
				co++;
			}
		}
		if(x % 7 == 1 || x%7==5){
			if (b < 1){
				break;
			}
			else{
				b --;
				co++;
			}
		}
		if(x % 7 == 2 || x%7==4){
			if (c < 1){
				break;
			}
			else{
				c --;
				co++;
			}
		}
	}
	return co;
}
signed main() {
	int a,b,c;
	int ans=0;
	cin >> a >> b >> c;
	while(a >= 3 && b >=2 && c >= 2){
		ans += 7;
		a-=3;
		b-=2;
		c-=2;
	}
	int ans1 = 0;
	for(int i=0;i<=6;i++){
		int ansi = solve(a,b,c,i);
		ans1=max(ans1,ansi);
	}
	cout << ans + ans1;
}