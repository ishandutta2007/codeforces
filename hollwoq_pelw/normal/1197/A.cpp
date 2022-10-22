#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        //cout << "#$#\n";
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a,a+n);
        int x = min(n-2, a[n-2]-1);
        cout << x << endl;
    }
	return 0;
}