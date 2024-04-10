#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int imace[2000005];
int niz[2000005];
int ind[2000005];
int koji[2000005];

vector <pair <int, int>> vec;

struct tri{
    int a, b, c;
} query[2000005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    int q;
    cin >> q;
    for(int i=1; i<=q; i++){
        cin >> query[i].a >> query[i].b;
        if(query[i].a == 1){
            cin >> query[i].c;
        }
    }
    int mxpay = 0;
    for(int i=1; i<=n; i++){
        imace[i] = -1;
    }
    for(int x=q; x>=1; x--){
        if(query[x].a == 1){
            int i = query[x].b;
            int val = query[x].c;
            if(imace[i] != -1) continue;
            imace[i] = val;
            ind[i] = x;
        }
        else{
            vec.push_back({query[x].b, x});
        }
    }
    reverse(vec.begin(), vec.end());
    int k = vec.size();
    for(int i=k-2; i>=0; i--){
        vec[i].first = max(vec[i].first, vec[i+1].first);
    }
    if(k > 0){
        for(int j=0; j<=vec[0].second; j++) koji[j] = vec[0].first;
    }
    for(int i=1; i<k; i++){
        //cout << vec[i-1].second << " do " << vec[i].second << endl;
        for(int j=vec[i-1].second+1; j<=vec[i].second; j++) koji[j] = vec[i].first;
    }
    for(int i=1; i<=n; i++){
        if(imace[i] == -1){
            if(vec.size() > 0){
                //cout << vec[0].first << endl;
                cout << max(niz[i], vec[0].first) << " ";
            }
            else cout << niz[i] << " ";
        }
        else{
            //cout << ind[i] << "\n";
            cout << max(imace[i], koji[ind[i]]) << " ";
        }
    }
    return 0;
}
/*
1
50
3
2 300
1 1 5
2 30
*/