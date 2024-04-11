#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-3
#define f first
#define s second
#define MAXN 512345
#define INF LLONG_MAX/4

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    n++;
    while(true){
        set<int> s;
        s.insert(n%10);
        s.insert((n/10)%10);
        s.insert((n/100)%10);
        s.insert((n/1000)%10);
        if(s.size()==4)break;
        n++;
    }
    cout<<n<<endl;
    
}