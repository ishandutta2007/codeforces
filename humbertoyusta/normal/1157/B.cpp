#include<bits/stdc++.h>
#define inf 1000000007
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; string s;
    int a[10];
    cin >> n;
    cin >> s;
    for(int i=1; i<10; i++)
        cin >> a[i];
    char k;
    for(int i=0; i<s.size(); i++)
        if( a[s[i]-'0'] > s[i]-'0' ){
            for(int j=i; j<s.size(); j++){
                if( '0' + a[s[j]-'0'] < s[j] ) break;
                s[j] = '0' + a[s[j]-'0'];
            }
            break;
        }

    cout << s << '\n';

    return 0;
}