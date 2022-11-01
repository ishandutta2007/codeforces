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

int data[20][20];	//0:empty	9:X		2:O

bool ok(){
	//
	for(int i = 1;i <= 10;i++)
		for(int j = 1;j <= 6;j++)
			if(data[i][j] + data[i][j+1] + data[i][j+2] + data[i][j+3] + data[i][j+4] == 45)
				return 1;
	//
	for(int i = 1;i <= 6;i++)
		for(int j = 1;j <= 10;j++)
			if(data[i][j] + data[i+1][j] + data[i+2][j] + data[i+3][j] + data[i+4][j] == 45)
				return 1;
	//(/)
	for(int i = 1;i <= 10;i++)
		for(int j = 5;j <= 10;j++)
			if(data[i][j] + data[i+1][j-1] + data[i+2][j-2] + data[i+3][j-3] + data[i+4][j-4] == 45)
				return 1;
	//(\)
	for(int i = 1;i <= 10;i++)
		for(int j = 1;j <= 10;j++)
			if(data[i][j] + data[i+1][j+1] + data[i+2][j+2] + data[i+3][j+3] + data[i+4][j+4] == 45)
				return 1;
	return 0;
}

int main(){
//	freopen("C.txt","r",stdin);
	for(int i = 1;i <= 10;i++)
		for(int j = 1;j <= 10;j++){
			char c; cin >> c;
			if(c == '.') data[i][j] = 0;
			if(c == 'X') data[i][j] = 9;
			if(c == 'O') data[i][j] = 2;
		}
	
	for(int i = 1;i <= 10;i++)
		for(int j = 1;j <= 10;j++)
			if(data[i][j] == 0 && data[i-1][j]+data[i][j-1]+data[i+1][j]+data[i][j+1]+data[i-1][j-1]+data[i-1][j+1]+data[i+1][j+1]+data[i+1][j-1] >= 9){
				data[i][j] = 9;
				
				if(ok()){
					cout << "YES" << endl;
					return 0;
				}
				data[i][j] = 0;
			}
		
	cout << "NO" << endl;
	return 0;
}