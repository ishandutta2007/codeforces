// Kim D	Belarusian SU
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll cnt[1000002];

int main()
{
//	ios_base::sync_with_stdio(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    ll a;
    string s;
    ll deg2;
    ll mask;
    for(int i=0;i<t;i++){
        cin >> s >> a;
        deg2 = 1;
        mask = 0;
        while(a){
            if((a%10)%2){
                mask += deg2;
            }
            a /= 10;
            deg2 *= 2;
        }

        if(s == "+"){
            cnt[mask] ++;
        }else if(s == "-"){
            cnt[mask] --;
        }else{
            cout << cnt[mask] << endl;
        }
    }
	return 0;
}