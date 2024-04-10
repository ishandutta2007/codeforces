#include<bits/stdc++.h>
using namespace std;

int n;
int a[400005];
int p1[400005];
int p2[400005];

set<int> st1;
set<int> st2;


signed main(){
    int o; cin >> o;
    while(o--){
        cin >> n;
        st1.clear();
        st2.clear();
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++){
            st1.insert(i);
            st2.insert(i);
        }
        p1[1] = a[1];
        p2[1] = a[1];
        st1.erase(a[1]);
        st2.erase(a[1]);
        for(int i = 2; i <= n; i++){
            if(a[i] != a[i - 1]){
                st1.erase(a[i]);
                st2.erase(a[i]);
                p1[i] = a[i];
                p2[i] = a[i];
            }
            else{
                auto itr = st1.begin();
                p1[i] = *itr;
                st1.erase(itr);
                itr = --st2.lower_bound(a[i]);
                p2[i] = *itr;
                st2.erase(itr);
            }
            // for(auto itr = st2.begin(); itr != st2.end(); ++itr){
            //     cout << *itr << " ";
            // }
            // cout << endl;
        }
        for(int i = 1; i <= n; i++) cout << p1[i] << " ";
        cout << endl;
        for(int i = 1; i <= n; i++) cout << p2[i] << " ";
        cout << endl;
        
    }
}