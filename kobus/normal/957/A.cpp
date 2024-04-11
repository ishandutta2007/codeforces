
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
#define MAXN 512345
#define INF LLONG_MAX/2
#define MOD 1000000007
#define cte 10002
#define MAX LLONG_MAX


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(4);
    cout.setf(ios::fixed);

    int n;
    string s;
    cin>>n>>s;

    for(int i=0;i<n-1;i++){
        if(s[i]!='?'&& s[i]==s[i+1]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            if(i==0 || i==n-1 || s[i-1]=='?' || s[i+1]=='?' || s[i-1]==s[i+1]){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout<<"No"<<endl;
    
    return 0;
}