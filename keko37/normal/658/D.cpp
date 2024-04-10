#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=200100;

long long n, k, x, pol, pos, carry, sol;
int in[maxn];
int l[maxn];
int pluz[maxn];
int minuz[maxn];
long long lijevo, desno, num;

int main () {
	cin >> n >> k;
	for (int i=0; i<n+1; i++) {
		cin >> x;
		in[i]=x;
		if (x>0) pol=1; else pol=0;
		if (x<0) x=-x;
		pos=i;
		while (x) {
			if (pol) pluz[pos]+=x%2; else minuz[pos]+=x%2;
			x/=2;
			pos++;
		}
	}
	for (int i=0; i<maxn-1; i++) {
		pluz[i]+=carry;
		carry=pluz[i]/2;
		pluz[i]=pluz[i]%2;
	}
	carry=0;
	for (int i=0; i<maxn-1; i++) {
		minuz[i]+=carry;
		carry=minuz[i]/2;
		minuz[i]=minuz[i]%2;
	}
	pol=0;
	for (int i=maxn-1; i>=0; i--) {
		if (pluz[i]<minuz[i]) {
			pol=1;
			for (int j=0; j<maxn; j++) {
				swap(pluz[j], minuz[j]);
			}
		}
		if (pluz[i]!=minuz[i]) break;
	}
	carry=0;
	for (int i=0; i<maxn; i++) {
		minuz[i]+=carry;
		carry=minuz[i]/2;
		minuz[i]=minuz[i]%2;
		l[i]=pluz[i]!=minuz[i];
		if (pluz[i]<minuz[i]) carry=1;
	}
	for (int i=maxn-1; i>=0; i--) {
		if (l[i]) {
			lijevo=i;
			break;
		}
	}
	for (int i=0; i<maxn; i++) {
		if (l[i]) {
			desno=i;
			break;
		}
	}
	for (int i=lijevo; i>=0; i--) {
		num=num*2+l[i];
		if (lijevo-i>33) break;
		if (desno>=i && i<=n) {
			if (i==n) {
				if (pol) {
					if (in[i]+num!=0 && abs(in[i]+num)<=k) sol++;
				} else {
					if (in[i]-num!=0 && abs(in[i]-num)<=k) sol++;
				}
			} else {
				if (pol) {
					if (abs(in[i]+num)<=k) sol++;
				} else {
					if (abs(in[i]-num)<=k) sol++;
				}
			}
		}
	}
	cout << sol;
	return 0;
}