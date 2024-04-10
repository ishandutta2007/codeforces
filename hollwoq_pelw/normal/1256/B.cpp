#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[201000];
int cnt[110];
int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> n;
		for (int i=1;i<=n;i++){
			cin >> a[i];
			cnt[i] = 1;
		}
		for (int _=1;_<=n-1;_++)
		for (int i=n-1;i>=1;i--){
			if (a[i+1] < a[i] && cnt[i] == 1) swap(a[i+1], a[i]), cnt[i] = 0;
		}
		for (int i=1;i<=n;i++){
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}