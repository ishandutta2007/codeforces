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
int b[1111],n,used[1111],k;


int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> b[i];
	
	for (int j=1;j<=n;j++) {
		for (int i=1;i<=n;i++)
			if (!used[i] && b[i] == 0) {
				used[i] = 1;
				for (int j=i-k;j>0;j--) b[j]--;
				cout << i << " ";
				break;
			}
	}
	cout << endl;
	
	return 0;
}