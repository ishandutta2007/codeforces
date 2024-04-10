 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;
int n,m,k,sum=0;
string s;
main() {
     cin >> n >> m;
     cin >> s;
     for(int i=0;i<m;i++){
        int ii=0;
        while(ii<n-1){
            if (s[ii]=='B' && s[ii+1]=='G'){
                swap(s[ii],s[ii+1]);
                ii+=2;
            }
            else{
                ii+=1;
            }
        }
     }
     cout << s;





}