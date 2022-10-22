#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
bool f(int x){
    for(int i=0;i<25;i++){
        if (x == a[i]){
            return true;
        }
    }
    return false;
}
signed main() {
	int n;
	cin >> n;
	int x = 1;
	a.push_back(1);
	for(int i = 0;i < 24;i++){
        a.push_back((a[i] + 1) * 2  - 1);
	}
	if (f(n)){
        cout << 0;
        return 0;
	}
	int ans = 0;
	vector<int> ansi;
	int k = 1;
	while(true){
        if (f(n)){
            cout << ans << endl;
            for(int i=0;i<ansi.size();i++){
                cout << ansi[i] << " ";
            }
            return 0;
        }
        if (k == 1){
            int ii = -1,tmp = 0;
            int o = n;
            while(o){
                if (o % 2 == 0){
                    ii = tmp;
                }
                o /= 2;
                tmp++;
            }
            ans++;
            ii++;
            ansi.push_back((ii));
            n = n ^ ((2 << (ii - 1)) - 1);
           // cout << ((2 << (ii - 1)) - 1) << endl;
        }
        else{
            ans++;
            n++;
        }
        k = 3 - k;
       // cout << n << "ger "<<endl;

	}


}