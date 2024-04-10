#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    int uzet = 0;
    ll tr = 0;
    priority_queue <int> vals;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x > 0){
            tr += x;
            uzet++;
        }
        else{
            x = -x;
            if(tr >= x){
                tr -= x;
                uzet++;
                vals.push(x);
            }
            else if(!vals.empty() && vals.top() > x){
                tr += vals.top();
                vals.pop();
                tr -= x;
                vals.push(x);
            }
        }
    }
    cout << uzet << "\n";
    return 0;
}