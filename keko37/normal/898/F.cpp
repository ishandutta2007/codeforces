#include<iostream>

using namespace std;

const int MAXN = 1000005;

int n, naso;
int mod[10]={179426561, 179427007, 179427461, 179428003, 1000000007};
int h[MAXN] [10], pot[MAXN] [10];
string s;

int add (int x, int y, int ind) {
	x+=y;
	if (x>=mod[ind]) return x-mod[ind]; return x;
}

int sub (int x, int y, int ind) {
	x-=y;
	if (x<0) return x+mod[ind]; return x;
}

int mul (int x, int y, int ind) {
	return ((long long) x)*y%mod[ind];
}

int geth (int x, int y, int ind) {
	if (x==0) return h[y] [ind]; return sub(h[y] [ind], mul(h[x-1] [ind], pot[y-x+1] [ind], ind), ind);
}

void ok (int a, int b) {
	if (naso || a>=b || s[a]=='0' || s[b]=='0') return;
	//cout << "bok" << endl;
	for (int i=0; i<5; i++) {
		int x=geth(0, a-1, i);
		int y=geth(a, b-1, i);
		int z=geth(b, n-1, i);
		//cout << "bla " << x << " " << y << " " << z << endl;
		if (add(x, y, i)!=z) return;
	}
	naso=1;
	cout << s.substr(0, a) << "+" << s.substr(a, b-a) << "=" << s.substr(b, n-b);
}

void nadi () {
	if (n&1) {
		if (s[0]=='0' && s.substr(1, n/2)==s.substr(n/2+1, n/2)) {
			naso=1;
			cout << "0+" << s.substr(1, n/2) << "=" << s.substr(n/2+1, n/2);
		} else if (s[n/2]=='0' && s.substr(0, n/2)==s.substr(n/2+1, n/2)) {
			naso=1;
			cout << s.substr(0, n/2) << "+0=" << s.substr(n/2+1, n/2);
		}
	}
	int a, b;
	for (int i=0; i<n; i++) {
		a=i+1, b=n-i-1;
		ok(a, b);
		a=i+1, b=n-i-2;
		ok(a, b);
		a=n-2*i-2, b=n-i-1;
		ok(a, b);
		a=n-2*i-3, b=n-i-2;
		ok(a, b);
	}
}

int main () {
	cin >> s;
	n=s.size();
	for (int i=0; i<n; i++) {
		for (int j=0; j<5; j++) {
			h[i] [j]=s[i]-'0';
			if (i>0) h[i] [j]=add(h[i] [j], mul(h[i-1] [j], 10, j), j);
			if (i==0) {
				pot[i] [j]=1;
			} else {
				pot[i] [j]=mul(pot[i-1] [j], 10, j);
			}
		}
	}
	nadi();
	return 0;
}