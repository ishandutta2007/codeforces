#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define fi first
#define se second
#define np make_pair
#define int long long
const int maxN = 2e5 + 5;
int n, m;
int x, y, z;
int par[maxN];
int val[maxN];
pair<int, ii> qr[maxN];
int timejoin;
set<ii> st;
int money = 0;

int find(int i){
    if(i == par[i]) return i;
    else return par[i] = find(par[i]);
}

bool unite(int i, int j, int coin){
    i = find(i);
    j = find(j);
    if(i == j) return 0;
    par[i] = j;
    val[j] = min(val[j], val[i]);
    money += coin;
    return 1;
}

bool god(int i){
    if(i != find(i)) return 0;
    return 1;
}


signed main(){
    cin >> n >> m;
    timejoin = n - 1;
    for(int i = 1; i <= n; i++){
        par[i] = i;
        cin >> val[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        qr[i].fi = z;
        qr[i].se.fi = x;
        qr[i].se.se = y;
    }
    sort(qr + 1, qr + m + 1, greater<pair<int, ii>>());
    int cur = m;
    for(int i = 1; i <= n; i++){
        st.insert(ii(val[i], i));
    }
    while(cur && timejoin){
        ii p1 = (*st.begin());
        ii p2 = (*(++st.begin()));
        z = qr[cur].fi;
        if(z > p1.fi + p2.fi){
            if(unite(p2.se, p1.se, p1.fi + p2.fi)){
                st.erase(ii(val[p2.se], p2.se));
                timejoin--;
            }
        }
        else{
            int n1 = qr[cur].se.fi;
            int n2 = qr[cur].se.se;
            n1 = find(n1); n2 = find(n2);
            if(val[n1] > val[n2]) swap(n1, n2);
            if(unite(n2, n1, z)){
                timejoin--;
                st.erase(ii(val[n2], n2));
            }
            cur--;
        }
    }
    while(timejoin){
        ii p1 = (*st.begin());
        ii p2 = (*(++st.begin()));
        if(unite(p2.se, p1.se, p1.fi + p2.fi)){
            st.erase(ii(val[p2.se], p2.se));
            timejoin--;
        }
    }
    cout << money;
}