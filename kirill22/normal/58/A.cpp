 #include <bits/stdc++.h>
#define int long long
#define yes   cout << "YES";
#define no   cout << "NO";
using namespace std;
int n,m,k,o=0;
string s;
main() {
     cin >> s;
     char c='h';
     for(int i=0;i<s.size();i++){
        if (s[i]==c){
            o++;
            if (c=='h'){
                c='e';
                continue;
            }
            if (c=='e'){
                c='l';
                continue;
            }
            if (o==3){
                continue;
            }
            if (c=='l'){
                c='o';
            }
        }
     }
     if (o>=5){
        yes
     }
     else no


}