#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <memory.h>
using namespace std;
string s,t;
int f[255][255],n,who[255][255];


int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	cin >> s;
	cin >> t;
	
	memset(f,63,sizeof(f));
	for (int i='a';i<='z';i++) f[i][i] = 0;
	int n;
	cin >> n;
	while (n--) {
		char A,B;
		int x;
		cin >> A >> B >> x;
		f[A][B] = min(f[A][B],x);
	}
	
	for (int k='a';k<='z';k++)
		for (int i='a';i<='z';i++)
			for (int j='a';j<='z';j++)
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	
	for (int i='a';i<='z';i++)
			for (int j='a';j<='z';j++) {
				who[i][j] = 'a';
				for (int k='b';k<='z';k++)
					if (f[i][who[i][j]] + f[j][who[i][j]] > f[i][k] + f[j][k]) who[i][j] = k;
			}
				
	
	if (s.size() != t.size()) {
		cout << "-1" << endl;
		return 0;
	}
	
	long long ans = 0;
	for (int i=0;i<s.size();i++) {
		char need = who[s[i]][t[i]];
		int x = f[s[i]][need] + f[t[i]][need];
		if (x > 1e8) {
			cout << "-1" << endl;
			return 0;
		}
		s[i] = need;
		ans += x;
	}
	
	cout << ans << endl;
	cout << s << endl;
	
	return 0;
}