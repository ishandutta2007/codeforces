#include <bits/stdc++.h>

using namespace std;

#define init int i,j; ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define M 1000000007
#define all(group) group.begin(), group.end()
#define F(i,l,r) for(i=l; i!=r; r>l?i++:i--)
#define fill(arr,n) FOR(i,0,n) cin >> arr[i];
#define pr(x) cout << #x << ": " << x << "\n";
#define prArr(arr,n) FOR(i,0,n) cout << arr[i] << " "; cout << "\n";
#define prArr2D(arr2D,r,c) FOR(i,0,r){ prArr(arr2D[i],c); } 
#define P complex
#define X real()
#define Y imag()

int main(){
    init
    int T;
    cin >> T;
    while(T--) {
        int works[26];
        memset(works, 0, sizeof works);
        int len = 0;
        char c = '$';
        string s;
        cin >> s;
        int x = (int)s.length();
        F(i, 0, x) {
            if(s[i] == c)
                len++;
            else {
                if(len % 2 && c != '$')
                    works[c - 'a'] = 1;
                len = 1;
                c = s[i];
            }
        }
        if(len % 2)
            works[c - 'a'] = 1;
        F(i, 0, 26)
            if(works[i])
                cout << (char)(i + 'a');
        cout << endl;
    }
    return 0;
}