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

vector<int> pos[112];
bool rem[412345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
     
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        pos[s[i]-'a'].pb(i);
    }
    int l=0,c=0,r=0;
    while(r<k){
        //cout<<l<<" "<<c<<" "<<r<<endl;
        if(pos[l].size()<=c){
            l++;
            c=0;
            continue;
        }
        rem[pos[l][c]]=1;
        c++;
        r++;
    }
    for(int i=0;i<n;i++){
        if(!rem[i])cout<<s[i];
    }
    cout<<endl;

    return 0;
}