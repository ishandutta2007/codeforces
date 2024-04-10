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
        int n;
        cin >> n;
        int odd = 0, ones = 0;
        F(i, 0, n) {
            string s;
            cin >> s;
            if(s.length() % 2)
                odd = 1;
            for(char c : s)
                if(c == '1')
                    ones++;
        }
        cout << ((ones % 2) && !odd ? n - 1 : n) << endl;
    }
    return 0;
}