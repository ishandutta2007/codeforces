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
#define MAXN 512345
#define INF LLONG_MAX
#define MOD 32416187567
#define cte 10002
#define MAX ULLONG_MAX


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
        
    string s;
    cin>>s;

    int l=0,p=0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='-')l++;
        else p++;
    }

    if(p==0 || l%p==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;

}