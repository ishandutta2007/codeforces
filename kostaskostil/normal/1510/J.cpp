#include<bits/stdc++.h>

using namespace std;

int n;
string s;

void check0(){
    if(find(s.begin(), s.end(), '#') == s.end()){
        cout << "0\n";
        exit(0);
    }
    if(s[0] != '#')
        return;
    vector<int> ans;
    int lst = -1;
    for(int i = 1; i <= n; ++i){
        if(i == n || s[i] != '#'){
            if(lst+1 == i)
                return;
            ans.push_back(i-lst-1);
            lst = i;
        }
    }
    cout << ans.size() << "\n";
    for(int el : ans)
        cout << el << " ";
    cout << "\n";
    exit(0);
}

void check1(){
    if(s[0] == '#')
        return;
    vector<int> ans;
    int cnt = 2;
    int prv_ch = s[0];
    for(int i = 1; i <= n+1; ++i){
        char ch;
        if(i < n)
            ch = s[i];
        else if(i == n)
            ch = '_';
        else ch = '#';
        if(ch != prv_ch){
            if(ch == '#'){
                if(cnt%2)
                    return;
                for(int j = 0; j < cnt/2-1; ++j)
                    ans.push_back(1);
            }
            else ans.push_back(cnt+1);
            cnt = 0;
        }
        ++cnt;
        prv_ch = ch;
    }
    cout << ans.size() << "\n";
    for(int el : ans)
        cout << el << " ";
    cout << "\n";
    exit(0);
}
void build(int d){
    vector<int> ans;
    int cnt = d+1;
    int prv_ch = '_';
    for(int i = d; i <= n+1; ++i){
        char ch;
        if(i < n)
            ch = s[i];
        else if(i == n)
            ch = '_';
        else ch = '#';
        if(ch != prv_ch){
            if(ch == '#'){
                cnt -= d+1;
                if(cnt%2){
                    ans.push_back(2);
                    cnt -= 3;
                }
                for(int j = 0; j < cnt/2; ++j)
                    ans.push_back(1);
            }
            else ans.push_back(cnt+d);
            cnt = 0;
        }
        ++cnt;
        prv_ch = ch;
    }
    cout << ans.size() << "\n";
    for(int el : ans)
        cout << el << " ";
    cout << "\n";
    exit(0);
}
void fail(){
    cout << "-1\n";
    exit(0);
}

set<int> find_dists(){
    set<int> dists;
    int cnt = 1;
    int prv_ch = '_';
    for(int i = 0; i <= n+1; ++i){
        char ch;
        if(i < n)
            ch = s[i];
        else if(i == n)
            ch = '_';
        else ch = '#';
        if(ch != prv_ch){
            if(ch == '#')
                dists.insert(cnt);
            cnt = 0;
        }
        ++cnt;
        prv_ch = ch;
    }
    return dists;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    check0();
    check1();
    set<int> dists = find_dists();
    if(*dists.begin() >= 5) build(2);
    if(*dists.begin() == 4){
        if(next(dists.begin()) != dists.end() && *next(dists.begin()) == 5)
            fail();
        build(3);
    }
    if(*dists.begin() == 3){
        if(next(dists.begin()) != dists.end() && *next(dists.begin()) == 4)
            fail();
        build(2);
    }
    fail();
}