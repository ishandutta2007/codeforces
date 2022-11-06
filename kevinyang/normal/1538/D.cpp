#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isprime(int n){
	if(n<2)
        return 0;
    if(n==2||n==3)
        return 1;
    if(n%2==0||n%3==0)
        return 0;
    for(int i = 5; i <= sqrt(n); i+=6){
        if(n%i==0 || n%(i+2)==0)
            return 0;
    }
    return 1;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,k;
		cin >> a >> b >> k;
		if(k==1){
			if(a==b)cout << "No\n";
			else if(a%b==0||b%a==0)cout << "Yes\n";
			else cout << "No\n";
		}
		else{
			int cnt = 0;
			int v = a;
			for(int i = 2; i*i*i<=a; i++){
				while(v%i==0){
					v/=i;
					cnt++;
				}
			}
			if(v>1){
				if(isprime(v))cnt++;
				else cnt+=2;
			}
			v = b;
			for(int i = 2; i*i*i<=b; i++){
				while(v%i==0){
					v/=i;
					cnt++;
				}
			}
			if(v>1){
				if(isprime(v))cnt++;
				else cnt+=2;
			}
			if(cnt>=k){
				cout << "Yes\n";
			}
			else{
				cout << "No\n";
			}
		}
	}
	return 0;
}