#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];

    }
    multiset<int> s;
    for(int i = 0;i < n;i++){
        cin >> b[i];
        s.insert(b[i]);
    }
    for(int i = 0;i < n;i++){
        int x = a[i];
        int y;
        if (x == 0){
            y = 0;
        }
        else{
            y = n - x;
        }

        auto ind = s.lower_bound(y);
        if (ind == s.end()){
            int ind = *s.begin();
            cout << (x + ind) % n <<  " " ;
            s.erase(s.begin());
        }
        else{
            cout << (x + *ind) % n <<  " " ;
            s.erase(ind);
        }
    }


}