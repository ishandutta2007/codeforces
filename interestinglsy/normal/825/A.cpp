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

string s;
int len;
int main(){
	cin >> len;
	cin >> s;
	
	int nowi = 0;
	int lastnum;
	for(int i = 0;i < len;i++){
		if(s[i] == '1'){
			nowi++;
			lastnum = i;
		}
		else if(s[i] == '0' && i == lastnum + 1){
			cout << nowi;
			nowi = 0;
			lastnum = i+1;
		}
		else{
			cout << 0;
			nowi = 0;
			lastnum = i;
		}
	}
	
	cout << nowi << endl;
	
	return 0;
}