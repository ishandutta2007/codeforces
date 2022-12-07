#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;
char s[1111111];
int a[255];
bool u[255],f[255];

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    gets(s); int n = strlen(s);
    int k; cin >> k;
    
    for (int i=0;i<n;i++)
	a[ s[i] ]++;
    int cnt = 0;
    for (int i='a';i<='z';i++)
	if (a[i] == 0) a[i] = 2e8;
    
	
    for (int i=0;i<=26;i++) {
	int cool = 'a';
	for (int j='a';j<='z';j++)
	    if (a[j] < a[cool]) cool = j;
	if (a[cool] > k) break;
	
	
	u[cool] = 1;
	k -= a[cool];
	
	a[cool] = 2e8;
    }
    
    int ans = 0;
    for (int i=0;i<n;i++)
	if (!u[ s[i] ]) {
	    if (!f[ s[i] ]) ans++;
	    f[ s[i] ] = 1; 
	    
	    
	}
    cout << ans << endl;
    for (int i=0;i<n;i++)
	if (!u[ s[i] ]) putchar(s[i]);
    puts("");
    
    
    return 0;
}