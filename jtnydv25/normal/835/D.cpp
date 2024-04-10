#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
string s;
const int N = 5005;
bool pal[N][N];
int mx[N][N];
int find(int i, int j){
	if(mx[i][j]) return mx[i][j];
	if(!pal[i][j]) return 0;
	if(j == i) return mx[i][j] = 1;
	if(j == i + 1) return 2;
	int mid = (i + j) >> 1;
	if((j - i + 1) & 1){
		return mx[i][j] = min(find(i, mid - 1), find(mid + 1, j)) + 1;
	}
	return mx[i][j] = min(find(i, mid), find(mid + 1, j)) + 1;
}
int cnt[N], ans[N];
int main(){
    cin.tie(0);
    cin >> s;
    int n = s.length();
    s = "a" + s;
    for(int i = n; i >= 1; i--){
    	pal[i][i] = 1;
    	pal[i][i + 1] = (s[i] == s[i + 1]);
    	for(int j = i + 2; j <= n; j++)
    		pal[i][j] = (s[i] == s[j]) && pal[i + 1][j - 1];
    }
    for(int i = 1; i <= n; i++)
    	for(int j = i; j <= n; j++)
    		if(pal[i][j]) cnt[find(i, j)]++;
    for(int i = 1; i <= n; i++)
    	for(int j = 1; j <= i; j++)
    		ans[j] += cnt[i];
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";

}