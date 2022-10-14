#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long llint;

llint n;

llint f (llint x) {
	if (x<10) return x;
	vector <int> v;
	while (x) {
		v.push_back(x%10);
		x/=10;
	}
	reverse(v.begin(), v.end());
	llint res=0, cnt=0, y=0, sum, t, res2;
	res=v[0]-1;
	cnt=v[0]-1;
	sum=v[0];
	res2=v[0];
	for (int i=1; i<v.size(); i++) {
		res=res*10+9;
		y=y*10+v[i];
		res2*=10;
		cnt+=9;
	}
	t=f(y);
	res2+=t;
	while (t) {
		sum+=t%10;
		t/=10;
	}
	if (cnt>sum) {
		return res;
	} else {
		return res2;
	}
}

int main () {
	cin >> n;
	cout << f(n);
	return 0;
}