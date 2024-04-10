#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n,m,ans = 0;
	cin >> n >> m ;
	vector<int> a(n);
	for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    vector<int> b(m);
    for(int i = 0;i < m;i++){
        cin >> b[i];
    }
    int a1=0,a2=0,a3=0,a4=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            a1++;
        }
        else{
            a2++;
        }
    }
    for(int i=0;i<m;i++){
        if(b[i]%2==0){
            a3++;
        }
        else{
            a4++;
        }
    }
    cout << min(a1,a4) + min(a2,a3);

}