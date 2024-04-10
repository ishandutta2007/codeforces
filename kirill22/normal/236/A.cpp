 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;
int n,m,k,o=0,sum=0;
string s;
main() {
     cin >> s;
     int a[33]={0};
     for(int i=0;i<s.size();i++){
        a[s[i]-'a']=1;
     }
     for(int i=0;i<33;i++){
        sum+=a[i];
     }
     if (sum%2==0){
        cout << "CHAT WITH HER!";
     }
     else cout << "IGNORE HIM!";



}