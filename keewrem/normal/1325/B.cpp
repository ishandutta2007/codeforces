#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
int N,t,k;
using namespace std;
int main(){
    cin >> t;
    while(t--){
        set<int> a;
        cin >> N;
        while(N--){
            cin >> k;
            a.insert(k);
        }
        cout << a.size()<<"\n";
    }
    return 0;
}