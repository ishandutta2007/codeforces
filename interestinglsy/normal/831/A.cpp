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
#define mp make_pair
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

int n;

int main(){
//	freopen("A.txt","r",stdin);
	cin >> n;
	int stat = -1;
	int last = -1;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		if(x > last  &&  stat != 0){
			if(stat == 1  ||  stat == 2){
				cout << "NO" << endl;
				return 0;
			}
			stat = 0;
		}else if(x == last  &&  stat != 1){
			if(stat == 2){
				cout << "NO" << endl;
				return 0;
			}
			stat = 1;
		}else if(x < last  &&  stat != 2)
			stat = 2;
		last = x;
	}
	cout << "YES" << endl;
	
	return 0;
}