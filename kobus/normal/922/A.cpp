#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 2123456
#define INF LLONG_MAX
#define MOD 999999599
#define cte 10002
#define MAX 21234



int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int x,y;
    cin>>x>>y;

    int cop=y-1,ori=y;

    if(y<1 || (cop==0 && x!=0)){
        cout<<"No"<<endl;
    }
    else if(cop>=0 && x-cop>=0 && (x-cop)%2==0){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

    

    return 0;

}