 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;
bool f(int l){
    int b[10]={0};
    while(l){
        b[l%10]++;
        if (b[l%10]>1){
            return false;
        }
        l/=10;
    }
    return true;

}
int n,m,k,sum=0;
string s,s1,s2="";
main() {
     cin >>n;
     n++;
     while(! f(n)){
        n++;
     }
     cout << n;






}