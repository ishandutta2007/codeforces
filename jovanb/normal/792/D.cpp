#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll depth = 1;
ll root;
ll mask;
ll dpt;

ll lparent(ll node){
    return (1LL << (dpt-2)) + node;
}

ll rparent(ll node){
    return node - (1LL << (dpt-2));
}

ll parent(ll node){
    if(mask == 1) return node;
    dpt++;
    if(mask%2){
        mask /= 2;
        return rparent(node);
    }
    mask /= 2;
    return lparent(node);
}

ll left_child(ll node){
    if(node%2) return node;
    mask *= 2;
    ll x = (1LL << (dpt-1))-1;
    ll l = node-x;
    ll r = node-1;
    dpt--;
    return (l+r)/2;
}

ll right_child(ll node){
    if(node%2) return node;
    mask *= 2;
    mask++;
    ll x = (1LL << (dpt-1))-1;
    ll l = node+1;
    ll r = node+x;
    dpt--;
    return (l+r)/2;
}

void find_node(ll node){
    dpt = depth;
    mask = 1;
    ll res = root;
    while(1){
        if(node == res) return;
        else if(node < res){
            res = left_child(res);
        }
        else{
            res = right_child(res);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll n, q;
    cin >> n >> q;
    while(n /= 2){
        depth++;
    }
    root = (1LL << (depth-1));
    while(q--){
        ll s;
        cin >> s;
        find_node(s);
        //cout << dpt << " " << mask << endl;
        string str;
        cin >> str;
        for(auto c : str){
            if(c == 'L' && s%2 == 0){
                s = left_child(s);
            }
            if(c == 'R' && s%2 == 0){
                s = right_child(s);
            }
            if(c == 'U' && s != root){
                s = parent(s);
            }
            //cout << s << " ";
        }
        //cout << endl;
        cout << s << "\n";
    }
    return 0;
}