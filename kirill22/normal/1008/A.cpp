#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool Compare(string S1, string S2) {
    return S1==S2;
}
int main(){
    int h=0,h1=0,m,m1=0,c1;
    bool flag=true;
    char t;
    string s="Sad",s1="euioa",s2="";
    cin >> s;
    for(int i=0;i<s.size();i++){
        if (i==s.size()-1){

            if (s[i]!='n' && s1.find(s[i])==string::npos){
                cout << "NO";
                return 0;
            }
        }
        else if(s[i]=='n'){

            continue;
        }
        else{

            if (s1.find(s[i])==string::npos && (s1.find(s[i+1])==string::npos)){
                    cout << "NO";
                    return 0;

            }
        }
    }
    cout << "YES";

}