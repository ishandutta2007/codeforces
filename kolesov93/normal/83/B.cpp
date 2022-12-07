#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define N 211111
struct cell {
	int num; long long t;
	
	bool operator <(const cell& A) const {
		return t < A.t || (t == A.t && num < A.num);
	}
} b[N];

long long k; 
int n,a[N];
bool used[N];

int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	long long sum = 0;
	cin >> n >> k;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		sum += a[i];
		b[i].num = i; b[i].t = a[i];
	}
	sort(b,b+n);
	
	if (sum < k) {
		puts("-1");
		return 0;
	}
	if (sum == k) {
		puts("");
		return 0;
	}
	
	long long cnt = n, cur = 0;
	for (int i=0;i<n;i++) {
		if ((b[i].t - cur) * cnt <= k) {
			k -= (b[i].t - cur) * cnt;
			cnt--;
			used[ b[i].num ] = 1;
			cur = b[i].t;
		} else {
			long long del = k / cnt;
			cur += del + 1;
			k %= cnt;
			for (int j=0;j<n;j++) 
				if (!used[j]) {
					if (k > 0) {
						k--;
						if (cur >= a[j]) used[j] = 1;
					} else { 
						printf("%d ",j+1);
						used[j] = 1;
					}
				}
			for (int j=0;j<n;j++) 
				if (!used[j]) printf("%d ",j+1);
			
			return 0;
		}
	}
	
	return 0;
}