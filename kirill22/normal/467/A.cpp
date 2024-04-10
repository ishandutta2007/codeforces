 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;
int n,m,k,sum=0;
string s;
main() {
     cin >> n;
     int x=0,z=0,y=0;
     for(int i=0;i<n;i++){
        cin >> k >> m ;
        if (m-k>1){
            sum++;
        }
     }
     cout << sum;





}