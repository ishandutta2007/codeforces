#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

bool bfs(lol x, lol y){
    string a, b;
    while(x){
        a.push_back((x & 1) + '0');
        x >>= 1;
    }

    while(y){
        b.push_back((y & 1) + '0');
        y >>= 1;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    map<string, bool> pass;
    queue<string> q;
    q.push(a);

    while(q.size()){
        string top = q.front();
        q.pop();

        while(top[0] == '0') top.erase(top.begin());
        if(top.size() > b.size() && *top.rbegin() == '1') continue;
        pass[top] = 1;

        if(top == b) return true;

        reverse(top.begin(), top.end());
        if(pass.find("1" + top) == pass.end()) q.push("1" + top);
        if(pass.find(top) == pass.end()) q.push(top);
    }

    return false;
}

bool solve(lol x, lol y){
    if(x == y) return true;

    vector<int> a, b;
    while(x){
        a.push_back(x & 1);
        x >>= 1;
    }

    while(y){
        b.push_back(y & 1);
        y >>= 1;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(int i = 0; i + a.size() - 1 < b.size(); ++i){
        bool same = 1;
        for(int j = 0; j < a.size(); ++j) if(a[j] != b[i + j]){
            same = 0;
        }

        if(!same) continue;
        same = 1;
        int num = 0;
        for(int j = 0; j < i; ++j) same &= b[j];

        for(int j = i + a.size(); j < b.size(); ++j) same &= b[j], ++num;
        if(num == 0 && *a.rbegin() == 0) continue;

        if(same) return true;
    }

    auto temp = a;
    reverse(a.begin(), a.end());
    while(!a[0]) a.erase(a.begin());

    for(int i = 0; i + a.size() - 1 < b.size(); ++i){
        bool same = 1;
        for(int j = 0; j < a.size(); ++j) if(a[j] != b[i + j]){
            same = 0;
        }

        if(!same) continue;
        same = 1;
        for(int j = 0; j < i; ++j) same &= b[j];
        for(int j = i + a.size(); j < b.size(); ++j) same &= b[j];

        if(same) return true;
    }

    a = temp;
    a.push_back(1);
    reverse(a.begin(), a.end());
    while(!a[0]) a.erase(a.begin());

    for(int i = 0; i + a.size() - 1 < b.size(); ++i){
        bool same = 1;
        for(int j = 0; j < a.size(); ++j) if(a[j] != b[i + j]){
            same = 0;
        }

        if(!same) continue;
        same = 1;
        for(int j = 0; j < i; ++j) same &= b[j];
        for(int j = i + a.size(); j < b.size(); ++j) same &= b[j];

        if(same) return true;
    }

    a = temp;
    while(!(*a.rbegin())) a.erase(--a.end());

    for(int i = 0; i + a.size() - 1 < b.size(); ++i){
        bool same = 1;
        for(int j = 0; j < a.size(); ++j) if(a[j] != b[i + j]){
            same = 0;
        }

        if(!same) continue;
        same = 1;
        for(int j = 0; j < i; ++j) same &= b[j];
        for(int j = i + a.size(); j < b.size(); ++j) same &= b[j];

        if(same) return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    lol a, b;
    cin >> a >> b;

    cout << (solve(a, b) ? "YES" : "NO");
}