#include <bits/stdc++.h>
using namespace std;
long long q, n, b, a;
vector<long long> v;
vector<long long> d;
int main(){
	cin >> q;
	while(q--){
		v.clear();
        d.clear();
		cin >> n;
		for (long long i = 0; i < n; i++){
			cin >> b;
			v.push_back(b);
		}
		sort(v.begin(), v.end());
		a = v[0] * v[n - 1];
        for (long long i = 2; i * i <= a; i++){
            if(a % i == 0){
                d.push_back(i);
                if (i * i != a){
                    d.push_back(a / i);
                }
                if (d.size() > v.size()){
                	break;
				}
            }
        }
        bool f = 1;
        sort(d.begin(), d.end());
        if (d.size() != n){
            cout << -1 << endl;
            continue;
        }
        for (long long i = 0; i < n; i++){
            if (v[i] != d[i]){
                cout << -1 << endl;
                f = 0;
                break;
            }
        }
        if (f){
            cout << a << endl;
        }
	}
	return 0;
}