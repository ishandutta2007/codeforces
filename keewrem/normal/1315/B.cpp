#include <bits/stdc++.h>
using namespace std;
int t, a,b,p,n;
string s;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> p>>s;
        int n = s.size();
        char last='A';
        if(s[n-2]=='A')last = 'B';
        bool k = 0;
        for(int i = n-2; i >= 0; i--){
            if(s[i]!=last){
                if(last == 'B')p-=a;
                else p-= b;
                if(p < 0){cout << i+2;k=1;break;}
                last = s[i];
            }
        }
        if(!k)cout << 1;
        cout << "\n";
    }
    return 0;
}