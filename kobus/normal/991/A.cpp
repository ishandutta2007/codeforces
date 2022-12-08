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
     
    int a,b,c,d;
    cin>>b>>c>>d>>a;
    int resp=a-b-c+d;
    if(d>b || d>c || resp<1 || b>a || c>a || d>a)
        cout<<-1<<endl;
    else cout<<resp<<endl;

    return 0;
}