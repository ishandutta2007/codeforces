#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n,m,k;
    cin >> n;
    string s;
    cin >> s;
    int ans=0;

    for(int i=1;i<n;i++){
        if (s[i]!=s[i-1]){
            continue;
        }
        if (i==n-1){

            ans++;
            if (s[n-2]=='G'){
                s[n-1]='R';
            }
            else{
                s[n-1]='G';
            }
            break;
        }
        else{
                if (s[i]==s[i+1]){
                    ans++;
                    if (s[i+1]=='G'){
                        s[i]='R';
                    }
                    else{
                        s[i]='G';
                    }
                }
                else{
                    int k1=0,k2=0,k3=0;
                    if (s[i-1]=='R' || s[i+1]=='R' ){
                        k1=1;
                    }
                    if (s[i-1]=='G' || s[i+1]=='G' ){
                        k2=1;
                    }
                    if (s[i-1]=='B' || s[i+1]=='B' ){
                        k3=1;
                    }
                    if (k1==0){
                        s[i]='R';
                    }
                    else if(k2==0){
                        s[i]='G';
                    }
                    else{
                        s[i]='B';
                    }
                    ans++;
                }
        }

    }
    cout << ans << endl;
    cout << s;



}