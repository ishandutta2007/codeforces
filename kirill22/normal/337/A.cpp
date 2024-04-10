 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;

int n,m,k,sum=0;
string s,s1,s2="";
main() {
     cin >>n >> m;
     vector<int> a;
     for(int i=0;i<m;i++){
        cin >> k;
        a.push_back(k);
     }
     sort(a.begin(),a.end());
     int mini=a[n-1]-a[0];
     for(int i=0;i<=m-n;i++){
        mini=min(mini,a[i+n-1]-a[i]);
     }
     cout << mini;





}