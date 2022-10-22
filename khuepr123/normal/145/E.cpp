#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 5;

int n0[maxN * 4];
int n1[maxN * 4];
int n01[maxN * 4];
int n10[maxN * 4];
int a[maxN];
int l[maxN * 4];
int r[maxN * 4];
bool lck[maxN * 4];
char c;
int n, m;


void remake(int node){
    
    n0[node] = n0[node * 2] + n0[node * 2 + 1];
    n1[node] = n1[node * 2] + n1[node * 2 + 1];
    n01[node] = max(n0[node * 2] + n01[node * 2 + 1],
                   n01[node * 2] + n1[node * 2 + 1]);
    n10[node] = max(n1[node * 2] + n10[node * 2 + 1],
                   n10[node * 2] + n0[node * 2 + 1]);
    if(lck[node]){
        swap(n0 [node],  n1[node]);
        swap(n01[node], n10[node]);
    }
}

void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    if(left == right){
        n0[node] = 1 - a[left];
        n1[node] = a[left];
        n01[node] = 1;
        n10[node] = 1;
        return;
    }
    int mid = (left + right) / 2;
    build(node * 2    , left   , mid  );
    build(node * 2 + 1, mid + 1, right);
    remake(node);
}

void revert(int node, int left, int right){
    if(left == l[node] && right == r[node]){
        lck[node] = !lck[node];
        swap(n0 [node],  n1[node]);
        swap(n01[node], n10[node]);
        return;
    }
    else if(r[node * 2] < left)  revert(node * 2 + 1, left, right);
    else if(l[node * 2 + 1] > right) revert(node * 2, left, right);
    else{
        revert(node * 2    , left,      r[node * 2]);
        revert(node * 2 + 1, l[node * 2 + 1], right);
    }
    remake(node);
    
}

string s;
int x, y;


signed main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> c;
        if(c == '4') a[i] = 0;
        else a[i] = 1;
    }
    build(1, 1, n);
    while(m--){
        cin >> s;
        if(s == "count"){
            cout << n01[1] << endl; 
        }
        else{
            cin >> x >> y;
            revert(1, x, y);
        }
    //     for(int i = 1; i <= 13; i++){
    //     cout << n0[i] << " ";
    //     cout << n1[i] << " ";
    //     cout << n01[i] << " ";
    //     cout << n10[i] << " ";
    //     cout << "        ";
    //     cout << l[i] << " " << r[i];
    //     cout << "        ";
    //     cout << lck[i];
    //     cout << endl;
        
    // }
    // cout << endl;
    }
}