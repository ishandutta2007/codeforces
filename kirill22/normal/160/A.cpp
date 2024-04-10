 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;
int n,m,k,sum=0;
string s;
main() {
     cin >> n;
     vector<int>a;
     for(int i=1;i<=n;i++){
        cin >> m;
        sum+=m;
        a.push_back(m);
     }
     sort(a.rbegin(),a.rend());
     for(int i=1;i<=n;i++){
        int o=0;
        for(int u=0;u<i;u++){
            o+=a[u];
        }
        if (o>sum-o){
            cout << i;
            return 0;
        }

     }





}