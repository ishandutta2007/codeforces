#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define pb push_back
#define pii pair<int,int>
#define INF 9999999999
#define LINF 9999999999999999
#define SINF "%"
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define sint short int
#define usint unsigned sint
#define xsize(a) sizeof(a)/1024/1024
#define fr(aaaaa,bbbbb) for(aaaaa = 1;aaaaa <= bbbbb;aaaaa++)
#define frr(aaaaa,bbbbb,ccccc) for(aaaaa = ccccc;aaaaa <= bbbbb;aaaaa++)
using namespace std;
#define MAXN 100010

//Z algo
int z[MAXN];
int n;
char s[MAXN];

void getz(){
	int l=0,r=0;
	z[0] = 0;
	for(int i = 1;i < n;i++){
		if(i > r){
			l = r = i;
			while(r < n  &&  s[r-l] == s[r]) r++;
			r--;
			z[i] = r-l+1;
		}else{
			int k = i-l;
			if(z[k] < r-i+1) z[i] = z[k];
			else{
				l = i;
				while(r < n  &&  s[r-l] == s[r]) r++;
				r--;
				z[i] = r-l+1;
			}
		}
	}
}

int sum[MAXN];
void getsum(){
	int bucket[MAXN]; ms(bucket);	//bucket[i] z[k](k)i
	for(int i = 1;i < n;i++)
		bucket[z[i]]++;
	for(int i = n-1;i >= 1;i--)
		sum[i] = sum[i+1] + bucket[i];
}
int main(){
//	freopen("Prefixes and Suffixes.txt","r",stdin);
	cin >> s;
	n = strlen(s);
	getz();
	getsum();
	
	vector<int> a;
	vector<int> b;
	int ans = 0;
	for(int l = 1;l < n;l++)
	if(z[n-l] + n-l == n)
	{
		int times = 1;
		times += sum[l];
		if(times > 1){
			ans++;
			a.pb(l);
			b.pb(times);
		}
	}
	
	cout << ans+1 << endl;
	for(int i = 1;i <= ans;i++)
		cout << a[i-1] << " " << b[i-1] << endl;
	cout << n << " " << 1 << endl;
	
	return 0;
}
//ARC77:SS
//182d
//432d
//126b