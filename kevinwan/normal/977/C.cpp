/*
#include <bits/stdc++.h>
using namespace std;
int arr[26][26];
int main() {
	int n,i,j;
	string s;
	cin >> n >> s;
	int i;
	for (i = 0; i < n - 1; i++) {
		arr[s[i] - 'A'][s[i + 1] - 'A']++;
	}
	int op = 0;
	char a, b;
	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			if (arr[i][j] > op) {
				op = arr[i][j]; a = i + 'A'; b = j + 'A';
			}
		}
	}
	printf("%c%c", a, b);
}*/
#include <bits/stdc++.h>
using namespace std;
int arr[200001];
int main() {
	int n , k,i;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)scanf("%d", arr + i);
	sort(arr, arr + n);
	arr[n] = 0x3f3f3f3f;
	int ans;
	if (k == 0)ans = arr[0] - 1;
	else ans = arr[k - 1];
	if (ans == arr[k]||ans==0||ans>1000000000) {
		printf("-1"); return 0;
	}
	printf("%d", ans);
}