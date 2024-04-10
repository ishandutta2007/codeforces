#include<iostream>
#include<queue>
#include<vector>
using namespace std;

queue<int> vert;
vector< pair<int,int> > edges; int no;
int deg[66000], s[66000];
int n;

void solve(void){
    int i;
    while (!vert.empty()){
        i = vert.front();
        vert.pop();
        if (deg[i] == 1){

            deg[s[i]]--; deg[i]--;
            s[s[i]] = s[s[i]] ^ i;
            if (deg[s[i]] == 1)  vert.push(s[i]);
            edges.push_back(make_pair(i,s[i]));
            no++;
       }
    }
}
int main(void){
    cin >> n;
    int i;
    for(i=0;i<=n-1;i++){
        cin >> deg[i] >> s[i];
        if (deg[i] == 1){
            vert.push(i);
        }
    }

    solve();

    cout << no << "\n";
    vector<pair<int,int> >::iterator it = edges.begin();
    for(i=1;i<=no;i++){
        cout << (*it).first << " " << (*it).second << "\n";
        it++;
    }


}