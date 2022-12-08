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
#define MAX 21234


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    string s;
    cin>>s;

    cout<<s;
    for(int i=0;i<s.size()-1;i++)cout<<s[s.size()-i-2];
    cout<<endl;

    return 0;

}