#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 1000005;
 
int n;
char str[MAXN];
 
int main(){
	scanf("%d",&n);
	scanf("%s", str);
	int dx = 0;
	int ret = 0;
	for(int i=0; str[i]; i++){
		int cdx = dx;
		if(str[i] == '(') dx++;
		else dx--;
		if(cdx + dx < 0) ret++;
	}
	if(dx) ret = -1;
	cout << ret << endl;
}