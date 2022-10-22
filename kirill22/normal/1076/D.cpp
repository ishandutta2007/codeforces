#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long INF = 1e16;
int gcd(int a,int b){

    if (a<b){
        swap(a,b);
    }
    if (b==0){
        return a;
    }

    return gcd(b,a%b);

}

int main() {
    long long n, m, k;
    long long x, y, d;
    cin >> n >> m >> k;
    vector <vector<pair<long long, pair<long long,long long>>>> a(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> d;
        x--;y--;
        a[x].push_back({y,{d,i}});
        a[y].push_back({x,{d,i}});
    }
    vector<long long> ans;
    vector <long long> D(n, INF);
    D[0] = 0;
    long long kol=0;
    set <pair<long long, long long>> st;
    st.insert({0, 0});
    vector<long long> pred(n,-(1));

    while(! st.empty() && kol<k){
        long long v= st.begin()->second;
        st.erase(st.begin());
        if (pred[v]!=-(1)){
            ans.push_back(pred[v]+1);
            kol++;
        }
        for(int i=0;i<a[v].size();i++){
            ll b,w,pre;
            b=a[v][i].first;
            w=a[v][i].second.first;
            pre=a[v][i].second.second;
            if (D[b]>D[v]+w){
                st.erase({D[b],b});
                D[b]=D[v]+w;
                st.insert({D[b],b});
                pred[b]=pre;
            }

        }


    }
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

    return 0;
}