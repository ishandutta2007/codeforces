#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
//#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF LLONG_MAX
#define MOD 1000000007
#define cte 10002
#define MAX LLONG_MAX

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    string s;
    cin>>s;

    char c='a';

    for(int i=0;i<s.size();i++){
        //cout<<c<<" ";
        if(s[i]<=c && c!='z'+1){
            s[i]=c;
            c++;
        }
    }

    if(c!='z'+1){
        cout<<-1<<endl;
    }
    else cout<<s<<endl;


    return 0;
}