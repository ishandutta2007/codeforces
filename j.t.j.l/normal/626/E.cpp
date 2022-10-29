#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
const ll INF = (1LL) << 60;

ll a[MAXN];
ll sum[MAXN];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	sum[n+1] = 0;
	for(int i = n; i; i--)
		sum[i] = sum[i+1] + a[i];
	int ans = 0, p = 1, q = 0;
	for(int i = 2; i <= n - 1; i++){
	//	cout<<i<<endl; 
		int high = min(i - 1, n - i), low = 1, mid;
		int tmp = high;
		while(low + 1 < high){
			mid = (high + low) >> 1;
			if (a[i - mid] + a[n + 1 - mid] <= 2 * (sum[n + 1 - mid] + sum[i - mid] - sum[i+1]) / (2.0 * mid + 1))
				high = mid;
			else
				low = mid;
		}
		high = low;
		while (high < tmp && (a[i - high - 1] + a[n - high]) * (2 * high + 3) > 2 * (sum[n - high] + sum[i - high - 1] - sum[i + 1]))
			high++;
		while (high > 1 && (a[i - high + 1] + a[n - high + 2]) * (2 * high - 1) < 2 * (sum[n + 2 - high] + sum[i - high + 1] - sum[i + 1]))
			high--;
	//	if (high < tmp && a[i - high - 1] + a[n - high] > 2 * a[i])
	//		high++;
		if ((sum[n + 1 - high] + sum[i - high] - sum[i + 1]) * (2 * q + 1) - a[i] * (2 * high + 1) * (2 * q + 1) > (sum[n + 1 - q] + sum[p - q] - sum[p + 1]) * (2 * high + 1) - a[p] * (2 * high + 1) * (2 * q + 1)){
		//	cout<<(sum[n + 1 - q] + sum[p - q] - sum[p + 1]) / (2.0 * q + 1) - a[p]<<endl;
			p = i, q = high;
		//	cout<<(sum[n + 1 - q] + sum[p - q] - sum[p + 1]) / (2.0 * q + 1) - a[p]<<endl;
		}
	}
/*	if (n == 135707){
		cout<<((sum[n + 1 - q] + sum[p - q] - sum[p + 1]) - a[p] * (2 * q + 1))<<'/'<< 2 * q + 1<<endl;
		int i = p + 12 - (10603 - 6533) / 2;
		int high = min(i - 1, n - i), low = 1, mid;
		int tmp = high;
		while(low + 1 < high){
			mid = (high + low) >> 1;
			if (a[i - mid] + a[n + 1 - mid] <= 2 * a[i])
				high = mid;
			else
				low = mid;
		}
		high = low;
		cout<<high<<endl;
		cout<<2 * a[i]<<endl;
		cout<<a[i - high - 1] + a[n - high]<<endl;
		cout<<a[i - high] + a[n - high + 1]<<endl;
		cout<<a[i - high + 1] + a[n - high + 2]<<endl;
		cout<<a[i - 3265] + a[n - 3265 + 1]<<endl;
		cout<<a[i - 3266] + a[n - 3266 + 1]<<endl;
		cout<<a[i - 3267] + a[n - 3267 + 1]<<endl;
		while (high < tmp && a[i - high - 1] + a[n - high] > 2 * a[i])
			high++;
		while (high > 1 && a[i - high + 1] + a[n - high + 2] < 2 * a[i])
			high--;
	//	if (high < tmp && a[i - high - 1] + a[n - high] > 2 * a[i])
	//		high++;
		cout<<(sum[n + 1 - high] + sum[i - high] - sum[i + 1]) - a[i] * (2 * high + 1) <<'/'<< 2 * high + 1<<endl;
		if ((sum[n + 1 - high] + sum[i - high] - sum[i + 1]) * (2 * q + 1) - a[i] * (2 * high + 1) * (2 * q + 1) > (sum[n + 1 - q] + sum[p - q] - sum[p + 1]) * (2 * high + 1) - a[p] * (2 * high + 1) * (2 * q + 1)){
		//	cout<<(sum[n + 1 - q] + sum[p - q] - sum[p + 1]) / (2.0 * q + 1) - a[p]<<endl;
			p = i, q = high;
		//	cout<<(sum[n + 1 - q] + sum[p - q] - sum[p + 1]) / (2.0 * q + 1) - a[p]<<endl;
		}
	}*/
	printf("%d\n", 2 * q + 1);
	for(int i = p - q; i <= p; i++)
		printf("%d ", a[i]);
	for(int i = n + 1 - q; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}