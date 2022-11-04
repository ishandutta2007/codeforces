#include<bits/stdc++.h>
#define MAX 200
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int lp[100001];
vi pr;
void go(int l, int r, int can) {
	if(l == r) {
		cout << "B " << pr[l] << endl;
		int res;
		cin >> res;
		cout << "A " << pr[l] << endl;
		cin >> res;
		if(res >= 1) {
			cout << "C " << pr[l] << endl;
		} else {
			cout << "C 1" << endl;
		}
		return;
	}
	int mid = (l + r) / 2;
	for(int i = l; i <= mid; i++) {
		cout << "B " << pr[i] << endl;
		int res;
		cin >> res;
	}
	int res;
	cout << "A " << 1 << endl;
	cin >> res;
	if(res == can - (mid - l + 1)) {
		go(mid + 1, r, can - (mid - l + 1));
		return;
	}
	for(int i = l; i <= mid; i++) {
		cout << "A " << pr[i] << endl;
		int res;
		cin >> res;
		if(res > 0) {
			cout << "C " << pr[i] << endl;
			return;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    
    for(int i = 2; i <= 100000; i++) {
    	if(lp[i] == 0) {
    		lp[i] = i;
    		pr.push_back(i);
    	}
    	for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= 100000; j++) {
    		lp[i * pr[j]] = pr[j];
    	}
    }
    int n;
    cin >> n;
    vi ch;
    int now = 1;
    int max1 = 0;
    for(int i = 0; i < pr.size(); i++) {
    	if(n >= pr[i]) {
    		max1 = i;
    	} else {
    		break;
    	}
    }
    for(int i = 0; i < MAX; i++) {
    	ll st = pr[i];
    	while(true) {
    		if(st > n) {
    			break;
    		}
    		cout << "B " << st << endl;
    		int res;
    		cin >> res;
    		cout << "A " << st << endl;
    		cin >> res;
    		if(res == 1) {
    			now *= pr[i];
    			st *= pr[i];
    		} else {
    			break;
    		}
    	}
    }
    if(now == 1) {
    	if(max1 >= MAX) {
    		go(MAX, max1, max1 - MAX + 2);
    	} else {
    		cout << "C " << 1 << endl;
    	}
    	return 0;
    }
    for(int i = n / now; i >= 1; i--) {
    	bool ok = true;
    	for(int j = 0; j < MAX; j++) {
    		if(i % pr[j] == 0) {
    			ok = false;
    			break;
    		}
    	}
    	if(!ok) {
    		continue;
    	}
    	cout << "A " << i * now << endl;
    	int res;
    	cin >> res;
    	if(res != 0) {
    		cout << "C " << i * now << endl;
    		return 0;
    	}
    }
    cout << "C " << now << endl;
    /*int am = 0;
    for(int i = 1; i <= 100000; i++) {
    	for(auto el : ch) {
    		if(i % el == 0) {
    			++am;
    			break;
    		}
    	}
    }
    cout << am;*/

}