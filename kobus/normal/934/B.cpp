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
#define MAXN 212
#define INF LLONG_MAX
#define MOD 1000000007
#define cte 10002
#define MAX 21234


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    
    int k;
    cin>>k;

    string s;
    if(k/2+k%2>18){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<k/2;i++){
        s+='8';
    }
    if(k%2==1){
        s+='6';
    }
    cout<<s<<endl;

    return 0;

}