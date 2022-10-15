#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;

    deque<int> arr;
    for(int i = 0; i < n; ++i){
        int val;
        cin >> val;
        arr.push_back(val);
    }

    deque<int> q;
    if(arr.front() > arr.back()){
        q.push_back(arr.front());
        arr.pop_front();
    }
    else{
        q.push_back(arr.back());
        arr.pop_back();
    }

    while(!arr.empty()){
        if(arr.back() < q.front()){
            q.push_back(arr.back());
            arr.pop_back();
        }
        else if(arr.front() < q.front()){
            q.push_back(arr.front());
            arr.pop_front();
        }
        else break;
    }

    if(q.size() == n){
        while(!q.empty()) cout << q.front() << ' ', q.pop_front();
        cout << '\n';
        return;
    }
    else cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}