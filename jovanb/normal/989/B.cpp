#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int p, n;
    string str;
    cin >> n >> p;
    cin >> str;
    for(int i=0; i<n; i++){
        for(int j=i+p; j<n; j+=p){
            if(str[i] == '.'){
                if(str[j] == '.') str[j] = '1';
                if(str[j] == '1') str[i] = '0';
                else str[i] = '1';
                for(int x=0; x<n; x++){
                    if(str[x] == '.') cout << 0;
                    else cout << str[x];
                }
                return 0;
            }
            if(str[j] == '.'){
                if(str[i] == '.') str[i] = '1';
                if(str[i] == '1') str[j] = '0';
                else str[j] = '1';
                for(int x=0; x<n; x++){
                    if(str[x] == '.') cout << 0;
                    else cout << str[x];
                }
                return 0;
            }
            if(str[i] != str[j]){
                for(int x=0; x<n; x++){
                    if(str[x] == '.') cout << 0;
                    else cout << str[x];
                }
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}