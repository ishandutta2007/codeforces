#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int niz[100005];

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    int n;
    cin >> n;
    int sum = 0;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    sum = niz[1];
    queue <int> q;
    q.push(1);
    for(int i=2; i<=n; i++){
        if(niz[i]*2 <= niz[1]){
            sum += niz[i];
            q.push(i);
        }
        else sum -= niz[i];
    }
    if(sum <= 0){
        cout << 0;
        return 0;
    }
    cout << q.size() << "\n";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}