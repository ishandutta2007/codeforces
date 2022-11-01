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
#define MAXN 1100

char f[29],s[29];
char inp[MAXN];
int n;

int table[MAXN];	//table[i]=x  :   i  f  x  , 
// f = DA
// table[D] = 0;
//	   table[A] = 1;

int main(){
//	freopen("1.txt","r",stdin);
	
	cin >> f; cin >> s;
	cin >> inp; n = strlen(inp);
	
	for(int i = 0;i < 26;i++)
		table[f[i]-'a'] = i;
	
	for(int i = 0;i < n;i++){
		if('0' <= inp[i]  &&  inp[i] <= '9') cout << inp[i];
		else if('a' <= inp[i]  &&  inp[i] <= 'z') cout << s[table[inp[i]-'a']];
		else cout << (char)(s[table[inp[i]-'A']]-'a'+'A');
	}
	
	cout << endl;
}