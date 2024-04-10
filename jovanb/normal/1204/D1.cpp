#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int lis[2005];
int oldlis[2005];
int pre[2005];

string s;

int n;

/*void calc(){
    for(int i=1; i<=n; i++){
        pre[i] = pre[i-1];
        if(s[i-1] == '1') pre[i]++;
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(s[j-1] == '0') lis[i][j] = max(j-i+1-(pre[j]-pre[i-1]), lis[i][j-1]);
            else lis[i][j] = lis[i][j-1] + 1;
        }
    }
}*/

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> s;
    n = s.size();
    for(int i=1; i<=n; i++){
        pre[i] = pre[i-1];
        if(s[i-1] == '1') pre[i]++;
    }
    for(int i=1; i<=n; i++){
        if(s[i-1] == '0') continue;
        for(int j=0; j<=n; j++) lis[j] = 0;
        for(int j=i; j<=n; j++){
            if(s[j-1] == '0') lis[j] = max(j-i+1-(pre[j]-pre[i-1]), lis[j-1]);
            else lis[j] = lis[j-1] + 1;
            oldlis[j] = lis[j];
        }
        s[i-1] = '0';
        for(int i=1; i<=n; i++){
            pre[i] = pre[i-1];
            if(s[i-1] == '1') pre[i]++;
        }
        for(int j=0; j<=n; j++) lis[j] = 0;
        for(int j=i; j<=n; j++){
            if(s[j-1] == '0') lis[j] = max(j-i+1-(pre[j]-pre[i-1]), lis[j-1]);
            else lis[j] = lis[j-1] + 1;
            if(lis[j] != oldlis[j]){
                s[i-1] = '1';
                break;
            }
        }
    }
    cout << s;
    return 0;
}