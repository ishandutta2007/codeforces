#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int gcd(int a, int b) {
	int t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int f(int x) {
	if (x == 1) {
		return 1;
	}
	int c = 0;
	for (int i=1; i<x; i++) {
		if (gcd(i, x-i) == 1) {
			c++;
		}
	}
	return c;
}

int g(int x) {
	int c = 0;
	for (int i=1; i<=x; i++) {
		if (x % i == 0) {
			c += f(i);
		}
	}
	return c;
}

vector<int> p(1000000, 1);
vector<int> primes;

void sito() {
	for (long long i=2; i<1000000; i++) {
		if (p[i] == 1) {
			primes.push_back(i);
			for (long long j=i*i; j<1000000; j+=i) {
				p[j] = 0;
			}
		}
	}
}

long long totient_fast(long long x) {
	if (x == 1) {
		return 1;
	}

	long long y = x, z = x;
	
	for (int p : primes) {
		if (z % p == 0) {
			y = y / p * (p-1);
			while (z % p == 0) {
				z /= p;
			}
		}
	}

	if (z > 1) {
		y = y / z * (z-1);
	}

	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	sito();

	/*
	for (int i=1; i<=100; i++) {
		cerr << i << ' ' << f(i) << ' ' << (g(i) - i) << '\n';
	}
	*/
	

	long long n, k, tots;
	cin >> n >> k;

	tots = (k+1) / 2;

	while (n > 1 && tots > 0) {
		n = totient_fast(n);
		tots--;
	}

	cout << n % 1'000'000'007;
}