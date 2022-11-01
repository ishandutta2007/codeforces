#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int h, m, hh, mm;
int a[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

bool solve(){
	if(a[hh % 10] == -1 || a[hh / 10] == -1 || a[mm % 10] == -1 || a[mm / 10] == -1) return false;
	int mmm = a[hh % 10] * 10 + a[hh / 10], hhh = a[mm % 10] * 10 + a[mm / 10];
	if(hhh < h && mmm < m) return printf("%02d:%02d\n", hh, mm), true;
	return false;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d:%d", &h, &m, &hh, &mm);
		while(1){
			if(solve()) break;
			mm++;
			if(mm == m){
				mm = 0;
				hh++;
				if(hh == h) hh = 0;
			}
		}
	}
}