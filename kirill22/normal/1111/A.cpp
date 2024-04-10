#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s,s1;
    cin >> s >> s1;
    int n=s.size(),n1=s1.size();
    if (n!=n1){
        cout << "No";
        return 0;
    }
    for(int i=0;i<n;i++){
        if (s[i]=='a' || s[i]=='e' ||  s[i]=='u' || s[i]=='i' || s[i]=='o' ){
            if (s1[i]=='a' || s1[i]=='e' ||  s1[i]=='u' || s1[i]=='i' || s1[i]=='o' ){
            continue;
        }
        else{
            cout << "No";
        return 0;
        }
        }
        else if(s1[i]=='a' || s1[i]=='e' ||  s1[i]=='u' || s1[i]=='i' || s1[i]=='o'){
            if (s[i]=='a' || s[i]=='e' || s[i]=='u' || s[i]=='i' || s[i]=='o' ){
            continue;
        }
        else{
            cout << "No";
        return 0;
        }
        }
    }
    cout << "Yes";

}