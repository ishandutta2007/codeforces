
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll niz[200005];
ll seg[1000005];
ll lazy[1000005];

const ll INF = 1000000000000000000LL;

void init(int node, int l, int r){
    if(l == r){
        seg[node] = niz[l];
        return;
    }
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
    seg[node] = min(seg[node*2], seg[node*2+1]);
}

void propagate(int node, int l, int r){
    seg[node] += lazy[node];
    if(l == r){
        lazy[node] = 0;
        return;
    }
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
    lazy[node] = 0;
}

void upd(int node, int l, int r, int tl, int tr, int val){
    propagate(node, l, r);
    if(r < tl || tr < l) return;
    if(tl <= l && r <= tr){
        seg[node] += val;
        if(l != r){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (l+r)/2;
    upd(node*2, l, mid, tl, tr, val);
    upd(node*2+1, mid+1, r, tl, tr, val);
    seg[node] = min(seg[node*2], seg[node*2+1]);
}

ll query(int node, int l, int r, int tl, int tr){
    propagate(node, l, r);
    if(r < tl || tr < l) return INF;
    if(tl <= l && r <= tr) return seg[node];
    int mid = (l+r)/2;
    return min(query(node*2, l, mid, tl, tr), query(node*2+1, mid+1, r, tl, tr));
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    init(1, 1, n);
    int m;
    cin >> m;
    m++;
    while(m--){
        string s;
        getline(cin, s);
        //cout << "s je " << s << "\n";
        int cnt=0;
        for(auto c : s) if(c == ' ') cnt++;
        if(cnt == 1){
            int x = s.size();
            ll a=0, b=0;
            int i=0;
            while(i < x){
                if(s[i] == ' ') break;
                a = 10*a+(s[i]-'0');
                i++;
            }
            i++;
            while(i < x){
                if(s[i] == ' ') break;
                b = 10*b+(s[i]-'0');
                i++;
            }
            a++;
            b++;
            //cout << "e nego " << a << " " << b << "\n";
            if(a <= b){
                cout << query(1, 1, n, a, b) << "\n";
            }
            else{
                cout << min(query(1, 1, n, a, n), query(1, 1, n, 1, b)) << "\n";
            }
        }
        if(cnt == 2){
            int x = s.size();
            ll a=0, b=0, c=0;
            int i=0;
            while(i < x){
                if(s[i] == ' ') break;
                a = 10*a+(s[i]-'0');
                i++;
            }
            i++;
            while(i < x){
                if(s[i] == ' ') break;
                b = 10*b+(s[i]-'0');
                i++;
            }
            i++;
            int neg=0;
            while(i < x){
                if(s[i] == ' ') break;
                if(s[i] == '-') neg = 1;
                if(!neg && s[i] != '-') c = 10*c+(s[i]-'0');
                if(neg && s[i] != '-') c = 10*c-(s[i]-'0');
                i++;
            }
            a++;
            b++;
            if(a <= b){
                upd(1, 1, n, a, b, c);
            }
            else{
                upd(1, 1, n, a, n, c);
                upd(1, 1, n, 1, b, c);
            }
        }
        //cout << "m je " << m << "\n";
    }
    return 0;
}