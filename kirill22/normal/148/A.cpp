 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;

int n,m,k,sum=0,co=1,l,d;
string s,s1,s2="";
main() {
     cin >>k>>l>>m>>n>>d;
     for(int i=1;i<=d;i++){
        if (i%k!=0 && i%l!=0 && i%m!=0 && i%n!=0){
            sum++;
        }
     }
     cout << d-sum;




}