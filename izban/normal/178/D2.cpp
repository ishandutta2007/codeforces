#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=20;

int n,sum;
int a[maxn],b[maxn];
int sx[3], sy[3], sd[3];

bool p[maxn];
bool g[maxn];

map<int,int> mp;
map<int,bool> ff;

int f(int x) {
	if (x==0 || x==1) return 1;
	return x*f(x-1);
}

void dfs(int x) {
	if (x==n*n) {
		if (b[0]+b[5]+b[10]+b[15]==sum && b[12]+b[13]+b[14]+b[15]==sum && b[3]+b[7]+b[11]+b[15]==sum) {
			cout << sum << endl;
			for (int i=0; i<n*n; i++) {
				cout << b[i] << ' ';
				if ((i+1)%n==0) cout << endl;
			}			
			exit(0);
		}
		return;
	}
	if (!g[x]) {
		for (int i=0; i<n*n; i++) if (!p[i] && mp[a[i]]>0) {
			b[x]=a[i];
			mp[a[i]]--;
			bool f=true;
			if ((x+2)%n==0) {
				int k=b[x]+b[x-1]+b[x-2];
				if (mp[sum-k]>0) {
					mp[sum-k]--;
					b[x+1]=sum-k;
					g[x+1]=true;
				} else f=false;
			}
			if (x/n==2) {
				int k=b[x]+b[x-4]+b[x-8];
				if (mp[sum-k]>0) {
					mp[sum-k]--;
					b[x+4]=sum-k;
					g[x+4]=true;
				} else f=false;
			}
			if (x==9 && b[3]+b[6]+b[9]+b[12]!=sum) f=false;
			if (f) dfs(x+1);
			if (g[x+1]) {
				g[x+1]=false;
				mp[sum-(b[x]+b[x-1]+b[x-2])]++;
				b[x+1]=0;
			}
			if (g[x+4]) {
				g[x+4]=false;
				mp[sum-(b[x]+b[x-4]+b[x-8])]++;
				b[x+4]=0;
			}
			mp[a[i]]++;
			b[x]=0;
			g[x]=false;
		}
	}
	else dfs(x+1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n*n; i++)
		cin >> a[i];
	if (n<=3) {
	for (int oo=0; oo<f(n*n); oo++) {
		int s1=0;
		for (int i=0; i<3; i++) sx[i]=sy[i]=sd[i]=0;

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				sx[i]+=a[i+n*j];
				sy[i]+=a[j+n*i];
			}
		}
		if (n==1) {
			sd[0]=sd[1]=a[0];
		} else if (n==2) {
			sd[0]=a[0]+a[3];
			sd[1]=a[1]+a[2];
		} else {
			sd[0]=a[0]+a[4]+a[8];
			sd[1]=a[2]+a[4]+a[6];
		}
		bool f=true;
		for (int i=0; i<n; i++)
			f=f && sx[0]==sx[i] && sx[0]==sy[i];
		f=f && sx[0]==sd[1] && sx[0]==sd[0];
		if (f) {
			cout << sx[0] << endl;
			for (int i=0; i<n*n; i++) {
				cout << a[i] << ' ';
				if ((i+1)%n==0) cout << endl;
			}
			return 0;
		}
		next_permutation(a,a+9);
	}
	}
	else {
		sum=0;
		for (int i=0; i<n*n; i++) mp[a[i]]++, ff[a[i]]=true, sum+=a[i];
		for (int i=0; i<n*n; i++) 
			for (int j=i+1; j<n*n; j++) 
				if (a[i]==a[j]) p[j]=true;
		sum/=n;
		dfs(0);
	}
	return 0;
}