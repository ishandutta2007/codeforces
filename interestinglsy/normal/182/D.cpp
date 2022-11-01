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
#define MAXN 101000

//Z zlgo
int z[MAXN*2];
char s[MAXN*2],t[MAXN];
int n,m;

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

int main(){
//	freopen("1.txt","r",stdin);
	
	cin >> s; n = strlen(s);
	cin >> t; m = strlen(t);
	
	for(int i = 0;i < m;i++)
		s[n+i] = t[i];
	n += m;
	
	getz();
	
	int ans = 0;
	for(int l = 1;l <= max(n-m,m);l++){	//l:
		bool faild = 0;
		if(n % l  !=  0  ||  m % l  !=  0  ||  (n-m) % l  !=  0) continue;
		for(int i = l;i < n;i += l){
			if(z[i] < l){
				faild = 1;
				break;
			}
		}
		if(!faild){
			ans++;
			//cout << l << endl;
		}
	}
		
	cout << ans << endl;
	
	return 0;
}