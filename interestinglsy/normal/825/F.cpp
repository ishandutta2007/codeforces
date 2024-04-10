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
#define INF 9999999
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
#define MAXN 9000

//Z algo
int z[MAXN];
char s[MAXN];
int n;

void getz(string inp) {
	int len = inp.length();
	z[0] = len;
	int j = 0;
	for(int i = 1; i <= len;){
		for(;i + j < len  &&  inp[i + j] == inp[j];j++);
		if(z[i] = j){
			int k;
			for(k = 1;k + z[k] < z[i];k++)
				z[i + k] = z[k];
			i += k; j -= k;
		}
		else i++;
	}
}

int getmin[MAXN][MAXN];
void getmem(){//getmin[j][i]s=i,j 
	ms(getmin);
	string ss = string(s);
	for(int l = 0;l < n;l++){
		ms(z);
		getz(ss.substr(l));
		for(int d = 1;d <= n - l;d++){	//d	:	 
			int T = z[d] / d + 1;
			int r = l;
			for(int t = 1;t <= T;t++){
				r += d;						//r = l + z[d] + d 
				if(t > getmin[l][r])
					getmin[l][r] = t;
			}
		}
	}
}

int getwei(int x){
	if(0 <= x  &&  x <= 9) return 1;
	if(10 <= x  &&  x <= 99) return 2;
	if(100 <= x  &&  x <= 999) return 3;
	if(1000 <= x  &&  x <= 9999) return 4;
	if(10000 <= x  &&  x <= 99999) return 5;
	if(100000 <= x  &&  x <= 999999) return 6;
	if(1000000 <= x  &&  x <= 9999999) return 7;
	return 0;
}
int getminn(int a,int b){	//	[a,b]
	int ret = getmin[a][b];
	return getwei(ret) + (b - a) / ret;
}
//Dp
int mem[MAXN];		//mem[i]=x	:	i (0 < i <= n)
int dp(){
	for(int i = 1;i <= n;i++) mem[i] = INF; mem[0] = 0;
	for(int l = 0;l < n;l++)
		for(int r = l + 1;r <= n;r++)
			mem[r] = min(mem[r],mem[l] + getminn(l,r));
	return mem[n];
}

int main(){
	//freopen("E.txt","r",stdin);
	
	cin >> s;
	n = strlen(s);
	getmem();
	//for(int i = 1;i <= n;i++)
	//	cout << getmin[i][6] << " ";
	//return 0;
	int ans = dp();
	//for(int i = 1;i <= n;i++)
	//	cout << mem[i] << " ";
	//cout << endl;
	cout << ans << endl;
	
	return 0;
}