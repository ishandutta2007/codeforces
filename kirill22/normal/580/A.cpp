 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;

int n,m,k,sum=1,co=1;
string s,s1,s2="";
main() {
     cin >>m;
     vector<int> a;
     for(int i=0;i<m;i++){
        cin >> k;
        a.push_back(k);
     }
     for(int i=1;i<m;i++){
        if (a[i]>=a[i-1]){
            co++;
        }
        else{
            co=1;
        }
        sum=max(sum,co);
     }
     cout << sum;




}