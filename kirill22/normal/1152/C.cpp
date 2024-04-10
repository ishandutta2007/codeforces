#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int a, b;
	cin >> a >> b;
	if (a > b){
        swap(a,b);
	}
	if (a % b == 0 || b % a == 0){
        cout << 0;
        return 0;
	}
	int ans = 1e18, k = 0;
	k = 0;
	ans = a * b / __gcd(a,b);
	int x = b - a;
	for(int i = 1;i * i <= x;i++){
        if (x % i == 0){
            int b1 = b,a1 = a,ii = x/i;
            if(b1 % i !=0){
                if( (a +i - (b1 % i) ) * (b + i - (b1 % i)) / __gcd(a +i - (b1 % i),b+i - (b1 % i)) < ans){
                    k = i - (b1 % i);
                    ans = (a +i - (b1 % i) ) * (b + i - (b1 % i)) / __gcd(a +i - (b1 % i),b+i - (b1 % i));
                }
            }
            if(b1 % ii !=0){
                if( (a +ii - (b1 % ii) ) * (b + ii - (b1 % ii)) / __gcd(a +ii - (b1 % ii),b+ii - (b1 % ii)) < ans){
                    k = ii - (b1 % ii);
                    ans = (a +ii - (b1 % ii) ) * (b + ii - (b1 % ii)) / __gcd(a +ii - (b1 % ii),b+ii - (b1 % ii));
                }
            }

        }
	}
	cout << k;




}