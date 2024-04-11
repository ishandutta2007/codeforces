#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 112345
#define MAXM 1123456
#define INF LLONG_MAX/2
#define MOD 1000000007
#define cte 10002
#define MAX ULLONG_MAX
#define kada cout<<"karadola"<<endl;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
     
    int n;
    cin>>n;
    string s;
    cin>>s;

    for(int i=2;i<=n;i++){
        if(n%i==0)reverse(s.begin(),s.begin()+i);
    }
    cout<<s<<endl;

    return 0;
}