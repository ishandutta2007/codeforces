#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
	    if(c == '-')
			f = 1;
        c = getchar();
    }
    while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

inline int gcd(int a , int b){
	if(!b)
		return a;
	int r = a % b;
	while(r){
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

set < int > s;
mt19937 rnd(time(0));

int main(){
	int N , cnt = 0;
	cin >> N;
	int a = rnd() % N + 1;
	s.insert(a);
	cout << '?' << ' ' << a << endl;
	++cnt;
	cin >> a;
	int L = a , R = 1e9;
	while(L < R){
		int mid = L + R >> 1;
		cout << "> " << mid << endl;
		++cnt;
		int f;
		cin >> f;
		f ? L = mid + 1 : R = mid;
	}
	int ans = L - a;
	while(cnt < 60 && s.size() < N){
		int t = rnd() % N + 1;
		while(s.count(t))
			t = rnd() % N + 1;
		cout << '?' << ' ' << t << endl;
		++cnt;
		s.insert(t);
		cin >> t;
		ans = gcd(ans , R - t);
	}
	cout << "! " << R - (N - 1) * ans << ' ' << ans;
	return 0;
}