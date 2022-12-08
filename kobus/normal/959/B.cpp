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
#define INF LLONG_MAX
#define MOD 1000000007
#define cte 10002
#define MAX ULLONG_MAX

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);
    
    int n,k,m;
    cin>>n>>k>>m;

    map<string,int> group;
    map<int,int> cgroup;
    string st[112345];
    int cost[112345];



    for(int i=0;i<n;i++)cin>>st[i];
    for(int i=0;i<n;i++)cin>>cost[i];

    for(int i=1;i<=k;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            int word;
            cin>>word;
            word--;
            group[st[word]]=i;
            if(cgroup[i]==0)cgroup[i]=cost[word];
            else cgroup[i]=min(cgroup[i],cost[word]);
        }
    }
    int resp=0;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        resp+=cgroup[group[s]];
    }

    cout<<resp<<endl;


    return 0;

}