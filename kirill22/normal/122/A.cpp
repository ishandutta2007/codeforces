 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;
int n,m,k,o=0,sum=0;
string s;
main() {
     cin >> n;
     for(int i=1;i<=n;i++){
        bool flag=true;
        int ii=i;
        while(ii>0){
            int o=ii%10;
            if (!(o==4 || o==7)){
                flag=false;
                break;
            }
            ii/=10;
        }

        if (flag && n%i==0){
            yes
            return 0;
        }
     }
     no



}