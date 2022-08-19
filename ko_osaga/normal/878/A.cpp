#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, a1, a2, a3;
vector<pi> v;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		char buf[5];
		int x;
		scanf("%s %d",buf,&x);
		if(*buf == '|') v.push_back(pi(1, x));
		if(*buf == '&') v.push_back(pi(2, x));
		if(*buf == '^') v.push_back(pi(3, x));
	}
	a1 = 1023;
	for(int i=0; i<10; i++){
		int v0 = 0, v1 = 1;
		for(auto &j : v){
			int val = (j.second >> i) & 1;
			if(j.first == 1) v0 |= val, v1 |= val;
			if(j.first == 2) v0 &= val, v1 &= val;
			if(j.first == 3) v0 ^= val, v1 ^= val;
		}
		if(v0 == 0 && v1 == 0) a1 ^= (1<<i);
		if(v0 == 1 && v1 == 0) a2 |= (1<<i);
		if(v0 == 1 && v1 == 1) a3 |= (1<<i);
	}
	printf("3\n& %d\n^ %d\n| %d", a1, a2, a3);
}