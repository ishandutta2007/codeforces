#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

string t[1002];

int main()
{
    int n;
    cin >> n;
    string s;
    bool found = false;
    for(int i=0;i<n;i++){
        cin >> t[i];
    }
    for(int i=0;i<n;i++){
        if(found){
            break;
        }
        if(t[i][0]=='O' && t[i][1]=='O'){
            found = true;
            t[i][0] = '+';
            t[i][1] = '+';
            break;
        }
        if(t[i][3]=='O' && t[i][4]=='O'){
            found = true;
            t[i][3] = '+';
            t[i][4] = '+';
            break;
        }
    }
    if(!found){
        cout << "NO";
    }else{
        cout << "YES\n";
        for(int i=0;i<n;i++){
            cout << t[i] << endl;
        }
    }
    return 0;
}