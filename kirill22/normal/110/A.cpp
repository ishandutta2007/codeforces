 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;
int n,m,k,sum=0;
string s;
main() {
     cin >> n ;
     while(n>0){
        if (n%10==4 || n%10==7){
            sum++;
        }
        n/=10;
     }if (sum==0){
        no
        return 0;
     }
     while(sum){
        if (!(sum%10==4 || sum%10==7)){
            no;
            return 0;
        }
        sum/=10;
     }

     yes





}