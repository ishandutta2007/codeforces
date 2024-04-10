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
        string s;
        cin >> s;
        vector<char> odd, even;
        for(char c : s)
            if(c % 2)
                odd.push_back(c);
            else
                even.push_back(c);
        int iO = 0, iE = 0;
        while(iO < odd.size() || iE < even.size())
            if(iE == even.size() || (iO != odd.size() && odd[iO] < even[iE]))
                cout << odd[iO++];
            else
                cout << even[iE++];
        cout << endl;    
    }
    return 0;
}