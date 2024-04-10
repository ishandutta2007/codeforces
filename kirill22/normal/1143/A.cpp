#include<bits/stdc++.h>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin >> n ;
    vector<int> a(n);
    for(int i=0;i<n;i++){
    	cin >> a[i];
    }
    int i=n-1;
    while(i>-1 && a[i]==a[n-1]){
    	i--;
    }
    cout << i+1;

    return 0;

}