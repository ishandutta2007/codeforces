#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,e) for(int i=s;i<e;i++)
#define FOE(i,s,e) for(int i=s;i<=e;i++)
#define FOD(i,s,e) for(int i=s;i>=e;i--)
#define SET(a,e) memset(a,e,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PIL pair<int,LL>
#define PLI pair<LL,int>
#define PLL pair<LL,LL>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MOD 1000000007LL
 
int t;
int n;
int ans;
int a[1000005];
 
int main() {
//	scanf("%d", &t);
//	while (t--) {		
//	}
	scanf("%d", &n);
	FOE(i, 1, n) {
		scanf("%d", &a[i]);
		if (a[i] < 0) {
			a[i] = -a[i] - 1;
		}
	}
	if (n % 2 == 0) {
		FOE(i, 1, n) {
			printf("%d ", -a[i] - 1);
		}
		printf("\n");
		return 0;
	}
	else {
		int mn = 0;
		int mnx = 0;
		FOE(i, 1, n) {
			if (a[i] > mn && a[i] != 0) {
				mn = a[i];
				mnx = i;
			}
		}
		if (mnx == 0) {
			FOE(i, 1, n) {
				printf("%d ", 0);
			}
		}
		else {
			FOE(i, 1, n) {
				if (i != mnx) {
					printf("%d ", -a[i] - 1);
				}
				else printf("%d ", a[i]);
			}
		}
		printf("\n");
	}
	//printf("%d", ans);
	return 0;	
}