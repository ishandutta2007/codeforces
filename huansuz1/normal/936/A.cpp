#include <bits/stdc++.h>
using namespace std;

long long k,d,t, p;

int main() {
    cin >> k >> d >> t;
    if(k % d == 0){
    	cout << t;
    	return 0;
    }
    p =  (k + d - 1) / d;
    long double r = k + (p * d  - k) / 2.0;
    long long kk = t / r;
    long double ans = p * d * kk;
    long double lf = t - kk * r;
    if(lf <= k){
    	ans += lf;
    }
    else{
    	ans += k;
    	lf -= k;
    	ans += lf * 2.0;
    }
    printf("%.12lf", (double)(ans));
	return 0;
}