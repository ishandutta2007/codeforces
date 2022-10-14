#include<bits/stdc++.h>
#define inf 1000000007
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;

int a[200005], b[200005];
set<ii> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    //s.insert({inf,0});
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++){
        cin >> b[i];
        s.insert({b[i],i});
    }

    for(int i=1; i<=n; i++){
        auto op1 = s.begin();
        auto op2 = s.lower_bound({n-a[i],0});
        if( op2 == s.end() ){
            cout << ( a[i] + (*op1).f ) % n << ' ';
            s.erase(op1);
            continue;
        }
        if( ( a[i] + (*op1).f ) % n < ( ( a[i] + (*op2).f ) % n ) ){
            s.erase(op1);
        }
        else{
            cout << ( a[i] + (*op2).f ) % n << ' ';
            s.erase(op2);
        }
    }

    return 0;
}