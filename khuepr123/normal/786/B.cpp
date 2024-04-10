#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define iii pair<ii, int>
#define iiii pair<iii, int>
#define pb push_back
#define se second
#define fi first
#define n2de(i) ((i) + n)
#define n3de(i) ((i) + n * 5 - 1)
const int maxN = 1e5 + 5;
const int mod = 1e18 + 5;

struct makeEdge{
    int weight;
    int left;
    int right;
    int vertex;
}
;

struct makeEdge piece;
vector<makeEdge> query2;
vector<makeEdge> query3;

int start;
int cnt;

int n;
int a[maxN];
int tree[maxN * 4];
int l[maxN * 4];
int r[maxN * 4];
int ans[maxN];

vector<pair<int, int>> vc[maxN * 10];
void direct(int i, int j){
    vc[i].pb(ii(0, j));
}
void newpath(int i, int j, int anewweight){
    vc[i].pb(ii(anewweight, j));
}

void buildTree(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    if(left == right) return;
    int mid = (left + right) / 2;
    buildTree(node * 2, left, mid);
    buildTree(node * 2 + 1, mid + 1, right);
}

void update2(int node, int left, int right, int wei, int emit){
    if(l[node] == left && r[node] == right){
        newpath(emit, n2de(node), wei);
        return;
    } 
    if(left > r[node * 2]){
        update2(node * 2 + 1, left, right, wei, emit);
        return;
    }
    if(right < l[node * 2 + 1]){
        update2(node * 2, left, right, wei, emit);
        return;
    }
    update2(node * 2, left, r[node * 2], wei, emit);
    update2(node * 2 + 1, l[node * 2 + 1], right, wei, emit);
    return;
}

void update3(int node, int left, int right, int wei, int emit){
    if(l[node] == left && r[node] == right){
        newpath(n3de(node), emit, wei);
        return;
    }
    if(left > r[node * 2]){
        update3(node * 2 + 1, left, right, wei, emit);
        return;
    }
    if(right < l[node * 2 + 1]){
        update3(node * 2, left, right, wei, emit);
        return;
    }
    update3(node * 2, left, r[node * 2], wei, emit);
    update3(node * 2 + 1, l[node * 2 + 1], right, wei, emit);
    return;
}

void solve(){
    for(int i = 1; i <= n; i++){
        ans[i] = mod;
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, start));
    ans[start] = 0;
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int node = front.se;
        int dist = front.fi;
        if(dist != ans[node]) continue;
        for(int i = 0; i < vc[node].size(); i++){
            int child = vc[node][i].se;
            if(dist + vc[node][i].fi < ans[child]){
                ans[child] = dist + vc[node][i].fi;
                pq.push(ii(ans[child], child));
            }
        }
        // for(int i = 1; i <= n; i++){
        //     cout << ans[i] << " ";
        // }
        // cout << endl;
    }
    // cout << ans[n];
}

/*

job need to be done:
query 2:
connect all parent to child
connect all outer node to parent
query 3:
connect all child to parent
connect all parent to query 2's parent

*/

int t, x, y, www;

signed main(){
    cin >> n;
    int o; cin >> o;
    cin >> start;
    buildTree(1, 1, n);
    while(o--){
        cin >> t;
        if(t == 1){
            cin >> x >> y >> www;
            vc[x].pb(ii(www, y));
        }
        else{
            cin >> piece.vertex;
            cin >> piece.left;
            cin >> piece.right;
            cin >> piece.weight;
            if(t == 2) query2.pb(piece);
            if(t == 3) query3.pb(piece);
        }
    }
    buildTree(1, 1, n);
    for(int i = 1; i <= n * 4 - 1; i++){
        if(l[i] == 0) continue;
        if(l[i] == r[i]) direct(n2de(i), l[i]);
        else{
            direct(n2de(i), n2de(i * 2));
            direct(n2de(i), n2de(i * 2 + 1));
        }
    }
    for(int i = 0; i < query2.size(); i++){
        update2(1, query2[i].left, query2[i].right, query2[i].weight, query2[i].vertex);
    }
    buildTree(1, 1, n);
    for(int i = 1; i <= n * 4 - 1; i++){
        if(l[i] == 0) continue;
        if(l[i] == r[i]) direct(l[i], n3de(i));
        else{
            direct(n3de(i * 2 + 1), n3de(i));
            direct(n3de(i * 2)    , n3de(i));
        }
    }
    for(int i = 0; i < query3.size(); i++){
        update3(1, query3[i].left, query3[i].right, query3[i].weight, query3[i].vertex);
    }
    n = n * 9 - 2;
    solve();
    // for(int i = 1; i <= n; i++){
    //     cout << i << endl;
    //     for(int j = 0; j < vc[i].size(); j++){
    //         cout << "\t";
    //         cout << vc[i][j].fi << " " << vc[i][j].se << endl;
    //     }
    // }
    
    n = (n + 2) / 9;
    for(int i = 1; i <= n; i++){
        if(ans[i] == mod) cout << "-1 ";
        else cout << ans[i] << " ";
    }
    // for(int i = 1; i < 2 * n; i++){
    //     cout << i << " " << l[i] << " " << r[i] << endl;
    // }
}