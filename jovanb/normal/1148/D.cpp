#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct par{
    int f;
    int s;
    int ind;
};

vector <par> vec1;
vector <par> vec2;

bool cmp(par a, par b){
    return a.s > b.s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        if(a < b){
            vec1.push_back({a, b, i});
        }
        else vec2.push_back({a, b, i});
    }
    cout << max(vec1.size(), vec2.size()) << "\n";
    if(vec1.size() >= vec2.size()){
        sort(vec1.begin(), vec1.end(), cmp);
        for(auto c : vec1){
            cout << c.ind << " ";
        }
        return 0;
    }
    for(auto c : vec2){
        swap(c.f, c.s);
    }
    sort(vec2.begin(), vec2.end(), cmp);
    for(int i = vec2.size()-1; i>=0; i--){
        cout << vec2[i].ind << " ";
    }
    return 0;
}