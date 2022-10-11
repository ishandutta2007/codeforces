#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const ll maxn = 60;
const ll mod = 1e9;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, t, a;

string s;

bool p[maxn];

int main(){
	fast_io;
	
	p[1] = 1;
	
	for(ll i = 2; i < 50; i++){
		if(!p[i]){
			cout << i << endl;
			fflush(stdout);
			cin >> s;
			if(s == "yes"){
				a = i;
				t++;
			}
			for(ll j = i * i; j < 50; j += i){
				p[j] = 1;
			}
		}
	}
	
	if(t >= 2){
		cout << "composite";
		return 0;
	}
	if(t == 0 || a * a > 100){
		cout << "prime";
		return 0;
	}
	cout << a * a << endl;
	fflush(stdout);
	cin >> s;
	if(s == "yes"){
		cout << "composite";
	}
	else{
		cout << "prime";
	}
	
	return 0;
}