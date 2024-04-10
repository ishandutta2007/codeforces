#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi             map<int,int>
#define mii            map<int,pii>    
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)    for(int i=a;i<b;i++)
using namespace std;
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int square[]={4,9,25,49};
void solve()
{
    int cnt=0;
    rep(i,0,15){
        string s;
        cout<<primes[i]<<endl;
        fflush(stdout);
        cin>>s;
        if(s[0]=='y') cnt++;
    }   
    if(cnt>=2) {cout<<"composite";return;}
    cnt=0;
    rep(i,0,4){
        string s;
        cout<<square[i]<<endl;
        fflush(stdout);
        cin>>s;
        if(s[0]=='y') cnt++;
    }
    if(cnt) cout<<"composite";
    else cout<<"prime";
}

int main()
{
    int t=1;
//    cin>>t;
    while(t--)
        solve();
    return 0;
}