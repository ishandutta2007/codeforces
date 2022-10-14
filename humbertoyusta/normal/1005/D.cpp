#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;

string s;
int len,a[maxn],ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    len = s.size();

    for(int i=0; i<len; i++)
        a[i+1] = int( s[i] - '0' ) % 3;

    for(int i=1; i<=len; ){
        if( a[i] == 0 ){ ans++; i++; continue; }
        if( ( a[i] == 1 && a[i+1] == 2 ) || ( a[i] == 2 && a[i+1] == 1 ) ){
            ans++; i+=2; continue;
        }
        if( ( a[i] == 1 && a[i+1] == 1 && a[i+2] == 1 ) || ( a[i] == 2 && a[i+1] == 2 && a[i+2] == 2 ) ){
            ans++; i+=3; continue;
        }
        i++;
    }

    cout << ans;

    return 0;
}