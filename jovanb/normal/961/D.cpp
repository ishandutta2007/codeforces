#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct broj{
    ll p;
    ll q;
    bool operator ==(const broj &b){
        return p * b.q == q * b.p;
    }
};

struct point{
    ll x;
    ll y;
};

broj smer(point a, point b){
    broj r;
    r.q = a.x - b.x;
    r.p = a.y - b.y;
    return r;
}

point p[100005];
vector <int> vec;

int main(){

    int n;
    cin >> n;
    if(n <= 4){
        cout << "YES\n";
        return 0;
    }
    for(int i=1; i<=n; i++){
        cin >> p[i].x >> p[i].y;
    }
    broj b = smer(p[1], p[2]);
    for(int i=3; i<=n; i++){
        broj c = smer(p[1], p[i]);
        if(!(b == c)){
            vec.push_back(i);
        }
    }
    if(vec.size() <= 2){
        cout << "YES";
        return 0;
    }
    bool moze = 1;
    b = smer(p[vec[0]], p[vec[1]]);
    for(auto c : vec){
        broj d = smer(p[vec[0]], p[c]);
        if(!(b == d)){
            moze = 0;
        }
    }
    if(moze){
        cout << "YES";
        return 0;
    }
    vec.clear();
    b = smer(p[1], p[3]);
    for(int i=1; i<=n; i++){
        broj c = smer(p[1], p[i]);
        if(!(b == c)){
            vec.push_back(i);
        }
    }
    if(vec.size() <= 2){
        cout << "YES";
        return 0;
    }
    moze = 1;
    b = smer(p[vec[0]], p[vec[1]]);
    for(auto c : vec){
        broj d = smer(p[vec[0]], p[c]);
        if(!(b == d)){
            moze = 0;
        }
    }
    if(moze){
        cout << "YES";
        return 0;
    }
    vec.clear();
    b = smer(p[2], p[3]);
    for(int i=1; i<=n; i++){
        broj c = smer(p[2], p[i]);
        if(!(b == c)){
            vec.push_back(i);
        }
    }
    if(vec.size() <= 2){
        cout << "YES";
        return 0;
    }
    moze = 1;
    b = smer(p[vec[0]], p[vec[1]]);
    for(auto c : vec){
        broj d = smer(p[vec[0]], p[c]);
        if(!(b == d)){
            moze = 0;
        }
    }
    if(moze){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}