#include <bits/stdc++.h>
using namespace std;

pair <int, int> niz[10000];
int res[10000];
vector <int> v;

int main(){
    int t, j;
    cin >> t;
    while(t--){
        v.clear();
        int n;
        cin >> n;
        for(int i=0; i<n; i++) cin >> niz[i].first >> niz[i].second;
        j=0;
        for(int i=1; i<=10000; i++){
            if(j<n)while(i == niz[j].first){
                v.push_back(j);
                j++;
                if(j==n) break;
            }
            int x = v.size();
            for(int r=0; r<x; r++){
                if(niz[v[r]].second < i){
                    res[v[r]] = 0;
                    v.erase(v.begin()+r);
                    r--;
                    x--;
                }
            }
            if(!v.empty()){
                res[v[0]] = i;
                v.erase(v.begin()+0);
            }
        }
        for(int i=0; i<n; i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}