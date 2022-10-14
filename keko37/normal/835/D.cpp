#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 5005;

int n, b1=31337, b2=1000000007, x, y, d, t1, t2;
int pot1[MAXN], pot2[MAXN];
int h1[MAXN], h2[MAXN], h3[MAXN], h4[MAXN];
int dp[MAXN] [MAXN], sol[MAXN];
string s;

inline int get_h1 (int x, int y) {
	return x==0?h1[y]:h1[y]-h1[x-1]*pot1[y-x+1];
}

inline int get_h2 (int x, int y) {
	return x==0?h2[y]:h2[y]-h2[x-1]*pot2[y-x+1];
}

inline int get_h3 (int x, int y) {
	return y==n-1?h3[x]:h3[x]-h3[y+1]*pot1[y-x+1];
}

inline int get_h4 (int x, int y) {
	return y==n-1?h4[x]:h4[x]-h4[y+1]*pot2[y-x+1];
}

bool isti (int x1, int y1, int x2, int y2) {
	return get_h1(x1, y1)==get_h1(x2, y2) && get_h2(x1, y1)==get_h2(x2, y2);
}

bool palindrom (int x, int y) {
	return get_h1(x, y)==get_h3(x, y) && get_h2(x, y)==get_h4(x, y);
}

int main () {
	cin >> s;
	n=s.size();
	for (int i=0; i<n; i++) {
		if (i==0) {
			pot1[i]=1;
			pot2[i]=1;
		} else {
			pot1[i]=b1*pot1[i-1];
			pot2[i]=b2*pot2[i-1];
		}
		h1[i]=s[i]+(i==0?0:h1[i-1]*b1);
		h2[i]=s[i]+(i==0?0:h2[i-1]*b2);
	}
	for (int i=n-1; i>=0; i--) {
		h3[i]=s[i]+(i==n-1?0:h3[i+1]*b1);
		h4[i]=s[i]+(i==n-1?0:h4[i+1]*b2);
	}
	//cout << h3[5] << endl << h1[1] << endl;
	for (int i=0; i<n; i++) {
		dp[i] [i]=1;
		sol[1]++; 
	}
	for (int len=2; len<=n; len++) {
		for (int i=0; i+len-1<n; i++) {
			d=len/2;
			t1=dp[i] [i+d-1];
			t2=dp[i+len-d] [i+len-1];
			//cout << i << " " << i+d-1 << " " << i+len-d << " " << i+len-1 << endl;
			if (palindrom(i, i+len-1)) {
				dp[i] [i+len-1]=1;
			}
			
			if (d!=0 && t1!=0 && isti(i, i+d-1, i+len-d, i+len-1)) {
				dp[i] [i+len-1]=t1+1;
			}
			//cout << i << " " << i+len-1 << "  " << dp[i] [i+len-1] << endl;
			sol[dp[i] [i+len-1]]++;
		}
	}
	for (int i=n; i>=1; i--) {
		sol[i]+=sol[i+1];
	}
	for (int i=1; i<=n; i++) {
		printf("%d ", sol[i]);
	}
	//cout << endl << isti(1, 1, 2, 2);
	return 0;
}