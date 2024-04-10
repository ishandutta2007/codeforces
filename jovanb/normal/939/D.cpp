#include <bits/stdc++.h>
using namespace std;

vector <int> graf[27];
vector <pair <int, int>> resenja;

int niz1[1000000];
int niz2[1000000];

bool bio[30];

void dfs(int v){
    if(bio[v]) return;
    bio[v] = true;
    for(auto c : graf[v]) dfs(c);
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for(int i=0; i<n; i++){
        niz1[i] = s1[i]-'a';
        niz2[i] = s2[i]-'a';
        niz1[i]++;
        niz2[i]++;
    }
    for(int i=0; i<n; i++){
        if(niz1[i] == niz2[i]) continue;
        else{
            for(int i=1; i<=26; i++) bio[i] = 0;
            dfs(niz1[i]);
            if(!bio[niz2[i]]){
                resenja.push_back({niz1[i], niz2[i]});
                graf[niz1[i]].push_back(niz2[i]);
                graf[niz2[i]].push_back(niz1[i]);
            }
        }
    }
    cout << resenja.size() << "\n";
    for(auto x : resenja){
        char prvi = (x.first-1) + 'a';
        char drugi = (x.second-1) + 'a';
        cout << prvi << " " << drugi << "\n";
    }
    return 0;
}