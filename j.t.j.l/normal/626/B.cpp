#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
const ll INF = (1LL) << 60;

char s[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int p = 0, q = 0, r = 0;
	for(int i = 0; i < n; i++)
		if (s[i] == 'B')
			p++;
		else
			if (s[i] == 'G')
				q++;
			else
				r++;
	if (p >= 1 && q >= 1 && r >= 1)
		puts("BGR");
	else{
		if (!p & !q) {puts("R"); return 0;}
		if (!p & !r) {puts("G"); return 0;}
		if (!r & !q) {puts("B"); return 0;}
		if (p > 1) p = 2;
		if (q > 1) q = 2;
		if (r > 1) r = 2;
		if (p + q + r == 2){
			if (!p) puts("B");
			if (!q) puts("G");
			if (!r) puts("R");
			return 0;
		}
		if (p + q + r == 3){
			if (p == 2) puts("GR");
			if (q == 2) puts("BR");
			if (r == 2) puts("BG");
			return 0;
		}
		if (p + q + r == 4){
			puts("BGR");
			return 0;
		}
		/*
		string o = "";
		o += (char)(p + '0');
		o += (char)(q + '0');
		o += (char)(r + '0');
		switch (o){
			case "001" : puts("R"); break;
			case "010" : puts("G"); break;
			case "100" : puts("B"); break;
			case "002" : puts("R"); break;
			case "020" : puts("G"); break;
			case "200" : puts("B"); break;
			case "110" : puts("R"); break;
			case "101" : puts("G"); break;
			case "011" : puts("B"); break;
			case "022" : ;
			case "202" : ;
			case "220" : puts("RGB"); break;
			case "012" : puts("BR"); break;
			case "210" : puts("BR"); break;
			case "021" : puts("BG"); break;
			case "201" : puts("BG"); break;
			case "102" : puts("GR"); break;
			case "120" : puts("GR"); break;
		}*/
	}
	return 0;
}