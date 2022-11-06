#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	/*
	int len = 100000;
	vector<bool>prime(len+1);
	for(int i = 2; i<=100000; i++)prime[i] = true;
	for(int i = 2; i*i<=100000; i++){
		for(int j = i*i; j<=100000; j+=i){
			prime[j] = false;
		}
	}
	vector<int>primes(9592);
	int index = 0;
	for(int i = 0; i<=100000; i++){
		if(prime[i]){
			primes[index] = i;
			index++;
		}
	}
	*/
	while(t--){
		int n;
		cin >> n;
		if(n==1){
			cout << "FastestFinger\n";
		}
		else if(n%2==1||n==2){
			cout << "Ashishgup\n";
		}
		else{
			int count = 0;
			for(int i = 3; i<=100000; i+=2){
				while(true){
					if(n%i==0){
						n/=i; count++;
					}
					else break;
				}
			}
			int count2 = 0;
			while(true){
				if(n%2==0){
					n/=2; count2++;
				}
				else break;
			}
			if(n>1)count++;
			if(count==1&count2==1){
				cout << "FastestFinger\n";
			}
			else if(count==0&count2>1){
				cout << "FastestFinger\n";
			}
			else cout << "Ashishgup\n";
		}
	}
	return 0;
}