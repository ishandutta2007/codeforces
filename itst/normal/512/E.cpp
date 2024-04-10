#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

#define PII pair < int , int >
#define _ 1003
int N;
vector < int > nxt[_];
vector < PII > solve(int l , int r){
    if(l + 1 >= r) return vector < PII > ();
    int t = *lower_bound(nxt[r].begin() , nxt[r].end() , l + 1);
    vector < PII > move; move.push_back(PII(l , r));
    vector < PII > tp = solve(l , t);
    move.insert(move.end() , tp.begin() , tp.end());
    tp = solve(t , r);
    move.insert(move.end() , tp.begin() , tp.end());
    return move;
}

vector < PII > work(){
    for(int i = 1 ; i <= N ; ++i) nxt[i].clear();
    for(int i = 1 ; i <= N ; ++i){
        nxt[i].push_back(i % N + 1);
        nxt[i].push_back(i == 1 ? N : i - 1);
    }
    for(int i = 1 ; i <= N - 3 ; ++i){
        int a , b; cin >> a >> b;
        nxt[a].push_back(b); nxt[b].push_back(a);
    }
    for(int i = 1 ; i <= N ; ++i) sort(nxt[i].begin() , nxt[i].end());
    vector < PII > ans;
    for(int i = 1 ; i < nxt[1].size() ; ++i){
        vector < PII > tp = solve(nxt[1][i - 1] , nxt[1][i]);
        ans.insert(ans.end() , tp.begin() , tp.end());
    }
    return ans;
}

set < int > Edge[_];
int main(){
    cin >> N;
    vector < PII > frm = work() , to = work();
    cout << frm.size() + to.size() << endl;
    for(auto t : frm) cout << t.first << ' ' << t.second << endl;
    reverse(to.begin() , to.end());
    for(int i = 2 ; i <= N ; ++i){
        Edge[i].insert(i - 1); Edge[i].insert(i % N + 1);
        Edge[1].insert(i);
    }
    for(auto t : to){
        int p = 0 , q = 0;
        for(int i = 1 ; i <= N && !q ; ++i)
            if(Edge[i].count(t.first) && Edge[i].count(t.second))
                if(!p) p = i;
                else q = i;
        Edge[p].erase(q); Edge[q].erase(p);
        Edge[t.first].insert(t.second); Edge[t.second].insert(t.first);
        cout << p << ' ' << q << endl;
    }
    return 0;
}