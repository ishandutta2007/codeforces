#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

const int b = 7;
const int mx = 5040;
int cntl,cntr;

int gen(int x){
	int y = x;
	int ans=0;
	int q;
	int u;
	bool a[8]={};
	for(int j=7;j>=1;j--){
		
		ans*=7;
		q=y%j;
		u=0;
		while(q>=0 && u<8){
			u++;
			if(!a[u]){
				q--;
			}
		}

		a[u] = true;
		ans +=(u-1);
		y/=j;
	}
	return ans;
}

int main()
{
	int n,m;
	cin >> n >> m;
	int ans=0;
	int deg[]={1,7,49,343,2401,16807,117649,823543};
	int cur = 0;
	int cnt = 0;
	cntl=0;
	cntr=0;
	int ln,lm;
	cur = n-1;
	ln = cur;
	while(cur>0){
		ln = cur;
		cur /= b;
		cntl++;
	}
	cur = m-1;
	lm = cur;
	while(cur>0){
		lm = cur;
		cur /= b;
		cntr++;
	}
	if(cntr==0) cntr++;
	if(cntl==0) cntl++;
	cnt = cntr + cntl;
	if(cnt>=8){
		cout << 0;
		return 0;
	}
	if(n==1){
		swap(m,n);
		swap(cntr,cntl);
	}
	/*if(m==1){
		if(n==1){
			cout << 0;
			return 0;
		}
		ans = n-1;
		int k = (n-1)/7;
		bool bo = true;
		while(k!=0){
			if(bo){
				ans -= k;
			}else{
				ans += k;
			}
			k = k/7;
			bo = !bo;
		}
		cout << ans;
		return 0;
	}*/
	int x,y,z;
	for(int i=0;i<mx;i++){
		z = gen(i);
		x = z%deg[cntl];
		z /= deg[cntl];
		y = z%deg[cntr];
		if(x<n && y<m){
			ans++;
		}
	}
	cnt = 7-cnt;
	while(cnt>1){
		ans/=cnt;
		cnt--;
	}
	cout << ans;
}