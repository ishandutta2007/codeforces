#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

const int p = 998244353;

int n;
int f[maxn];
int prm[maxn], cnt;
bool tag[maxn];
int d[maxn], num[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 2;i <= n;i++){
		if(!tag[i]) prm[++cnt] = i, d[i] = 2, num[i] = 1;
		for(int j = 1;j <= cnt && prm[j] * i <= n;j++){
			tag[prm[j] * i] = true;
			if(i % prm[j]){
				num[prm[j] * i] = 1;
        		d[prm[j] * i] = d[i] * 2;
			}else{
				num[prm[j] * i] = num[i] + 1;
        		d[prm[j] * i] = d[i] / num[prm[j] * i] * (num[prm[j] * i] + 1);
				break;
			}
		}
	}
	f[1] = 1;
	for(int i = 2;i <= n;i++){
		f[i] = (f[i - 1] + d[i]) % p;
		if(i < n) f[i] = (f[i] + f[i - 1]) % p;
	}
	printf("%d", f[n]);
}