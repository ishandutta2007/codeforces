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
        if (tolower(s[i])!=s[i]){
            sum++;
        }
     }
    if (sum==s.size()){

        for(int i=0;i<s.size();i++){
                cout << char(tolower(s[i]));

        }
    }
    else if(sum==s.size()-1 && s[0]==tolower(s[0])){
            cout << char(toupper(s[0]));
        for(int i=1;i<s.size();i++){
                cout << char(tolower(s[i]));

        }
    }
    else{
        cout << s;
    }




}