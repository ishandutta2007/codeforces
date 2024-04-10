#include<bits/stdc++.h>
//This code is written by Itst
#define eps 1e-10
#define ld long double 
using namespace std;

ld dp[110][110] , point[110][2] , dis[110] , x00 , y00 , delta;
int N , K;

inline ld calc(ld x1 , ld y1 , ld x2 , ld y2){
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool check(ld mid){
    memset(dp , 0 , sizeof(dp));
    dp[0][0] = 1;
	for(int i = 1 ; i <= N ; ++i){
		ld p;
		if(dis[i] > mid){ 
			p = exp(1 - dis[i] * dis[i] / mid / mid);
			dp[i][0] = dp[i - 1][0] * (1 - p);
		}
		else
			p = 1;
		for(int j = 1 ; j <= i ; ++j)
			dp[i][j] = dp[i - 1][j - 1] * p + dp[i - 1][j] * (1 - p);
	}
	ld sum = 0;
	for(int i = K ; i <= N ; ++i)
		sum += dp[N][i];
	return sum * 1000 + delta > 1000;
}

int main(){
	dp[0][0] = 1;
	cin >> N >> K >> delta >> x00 >> y00;
	for(int i = 1 ; i <= N ; ++i){
		cin >> point[i][0] >> point[i][1];
		dis[i] = calc(point[i][0] , point[i][1] , x00 , y00);
	}
	ld L = 0 , R = 4e3;
	while(L + eps < R){
		ld mid = (L + R) / 2;
		check(mid) ? R = mid : L = mid;
	}
	cout << fixed << setprecision(8) << L;
	return 0;
}