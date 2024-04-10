#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    int n;
    cin >> n;
    vector <int> prvi;
    vector <int> drugi;
    int poc;
    if(n%4 == 0){
        cout << "0\n";
        poc = 1;
    }
    else if(n%4 == 1){
        cout << "1\n";
        prvi.pb(1);
        poc = 2;
    }
    else if(n%4 == 2){
        cout << "1\n";
        prvi.pb(1);
        poc = 3;
    }
    else{
        cout << "0\n";
        prvi.pb(1);
        prvi.pb(2);
        poc = 4;
    }
    for(int i=poc; i<=n; i+=4){
        prvi.pb(i);
        prvi.pb(i+3);
    }
    cout << prvi.size() << " ";
    for(auto c : prvi) cout << c << " ";
    cout << "\n";
    return 0;
}