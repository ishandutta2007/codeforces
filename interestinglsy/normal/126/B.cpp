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
#define MAXN 1000010

//Z
char s[MAXN];
int n;

int z[MAXN];
void getz(){
	z[0] = 0;
	int l = 0,r = 0;
	for(int i = 1;i < n;i++){
		if(i > r){
			l = r = i;
			while(r < n  &&  s[r] == s[r-l]) r++;
			r--;
			z[i] = r - l + 1;
		}else{
			int k = i-l;
			if(z[k] < r-i+1)
				z[i] = z[k];
			else{
				l = i;
				while(r < n  &&  s[r] == s[r-l]) r++;
				r--;
				z[i] = r-l+1;
			}
		}
	}
}

int main(){
	//freopen("password.txt","r",stdin);
	cin >> s;
	n = strlen(s);
	
	getz();
	int maxz = 0,ans = 0;
	for(int i = 1;i < n;i++){
  		if(z[i] == n-i && maxz >= n-i){
			ans = n-i;
			break;
		}
  		maxz = max(maxz,z[i]);
	}
	if(ans){
		for(int i = 0;i < ans;i++)
			cout << s[i];
		cout << endl;
	}else
		cout << "Just a legend" << endl;//
	return 0;
}