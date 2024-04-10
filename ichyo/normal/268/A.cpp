#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> home(n);
    vector<int> invite(n);
    for(int i = 0; i < n; i++){
        cin >> home[i] >> invite[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    if(i != j && home[i] == invite[j]){
        ans += 1;
    }

    cout << ans << endl;
    return 0;
}